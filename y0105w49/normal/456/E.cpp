#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <set>

using namespace std;

#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)

#define INF 2001000009
#define maX(a,b) (((a)>(b))?(a):(b))
//#define N 300007

typedef pair< int, int > ii;
typedef vector< int > vi;
typedef vector< ii > vii;

const int N = 300007;
int longestpath[N]={0};
int parents[N]={0};
int n,m,q;
vector<int> adjs[N];
set<int> children[N];
priority_queue<ii, vii, greater<ii> > pq;
int distbelow[N]={0};
char done[N]={0};

void maketree(int node, int parent) {
  foreach(v,adjs[node])
    if (*v!=parent)
      maketree(*v,node);
  parents[node]=parent;
  done[node]=1;
}

void fixtree(int node, int parent) {
  if (children[node].empty())
    return;
  int highcount = 0;
  int highthing = 0;
  foreach(v,children[node])
    if (distbelow[*v]==distbelow[node]-1) {
      highcount++;
      if (*v != parent)
        highthing=*v;
    }
  if (highcount!=1)
    if (highcount)
      return;
    else
      cout << "arst" << highcount << highthing << node << endl;
  if (!highthing) return;
  parents[node]=highthing;
  parents[highthing]=0;
  children[highthing].insert(node);
  children[node].erase(highthing);
  distbelow[node]=0;
  foreach(v,children[node])
    if (distbelow[*v]>=distbelow[node])
      distbelow[node]=distbelow[*v]+1;
  if (distbelow[node]+1>distbelow[highthing])
      distbelow[highthing]=distbelow[node]+1;
  fixtree(highthing,node);
}

int findparent(int node) {
  if (parents[node])
    return findparent(parents[node]);
  return node;
}

int findparent2(int node) {
  if (parents[parents[node]])
    return (parents[node]=findparent2(parents[node]));
  if (parents[node])
    return parents[node];
  return node;
}

int main() {

  ios_base::sync_with_stdio(0);cin.tie(0);

  cin >> n >> m >> q;

  int a,b;
  for (int i = 0; i<m; i++) {
    cin >> a >> b;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }

  //cout << ".." << endl;

  for (int i = 1; i<=n; i++)
    if (!done[i])
      maketree(i,0);

  //cout << ".." << endl;

  for (int i = 1; i<=n; i++)
    if (parents[i])
      children[parents[i]].insert(i);

  for (int i = 1; i<=n; i++)
    if (children[i].empty())
      pq.push(make_pair(0,i));

  ii p;
  while (!pq.empty()) {
    p=pq.top();
    pq.pop();
    if (parents[p.second]) {
      distbelow[parents[p.second]]=p.first+1;
      pq.push(make_pair(p.first+1,parents[p.second]));
    }
  }

  for (int i = 1; i<=n; i++)
    if (!parents[i])
      fixtree(i,0);

  for (int i = 1; i<=n; i++)
    if (!parents[i]) {
      int needtosee = 1;
      int nexthighest=-1;
      foreach(v,children[i])
        if (distbelow[*v]>nexthighest)
          if (needtosee && distbelow[*v]==distbelow[i]-1)
            needtosee=0;
          else
            nexthighest=distbelow[*v];
      longestpath[i]=nexthighest+1+distbelow[i];
    }

  parents[0]=0;

  //cout << ".." << endl;

  for (int i = 1; i<=n; i++)
    if (parents[parents[i]])
      findparent2(i);

  //cout << "Done!" << endl;

  int cmd,x,y,px,py,px2,py2,hx,hy,dx,dy,pot;
  for (int i = 0; i<q; i++) {
    cin >> cmd >> x;
    int stupid=0;
    if (cmd==1) {
      if (parents[x])
        parents[x]=findparent(x);
      cout << longestpath[findparent(x)] << endl;
    } else if (!stupid) {
      cin >> y;
      if (parents[x])
        parents[x]=findparent(x);
      x=findparent(x);
      if (parents[y])
        parents[y]=findparent(y);
      y=findparent(y);
      if (x!=y) {
        if (longestpath[x]<longestpath[y])
          swap(x,y);
        parents[y]=x;
        longestpath[x]=maX(longestpath[x],(longestpath[x]+1)/2+(longestpath[y]+1)/2+1);
      }
    }
    else {
      cin >> y;
      px=x;
      py=y;
      dx=0;
      dy=0;
      while (parents[px]) {
        px2=px;
        px=parents[px];
        dx++;
      }
      while (parents[py]) {
        py2=py;
        py=parents[py];
        dy++;
      }
      if (longestpath[px]%2==1 && dx && distbelow[px2] == longestpath[px]/2)
        hx=longestpath[px]/2;
      else
        hx=(longestpath[px]+1)/2;
      if (longestpath[py]%2==1 && dy && distbelow[py2] == longestpath[py]/2)
        hy=longestpath[py]/2;
      else
        hy=(longestpath[py]+1)/2;

      pot=hx+dx+1+dy+hy;
      if (pot<=longestpath[px]) {
        parents[y]=x;
        while (parents[y] && distbelow[parents[y]] <= distbelow[y]) {
          distbelow[parents[y]]=distbelow[y]+1;
          y=parents[y];
        }
        continue;
      }
      if (pot<=longestpath[py]) {
        parents[x]=y;
        while (parents[x] && distbelow[parents[x]] <= distbelow[x]) {
          distbelow[parents[x]]=distbelow[x]+1;
          x=parents[x];
        }
        continue;
      }

      int tmp,tmp2;
      if (hx+dx<hy+dy) {
        tmp=dx;
        dx=dy;
        dy=tmp;
        tmp=hx;
        hx=hy;
        hy=tmp;
        tmp=x;
        x=y;
        y=tmp;
        tmp=px;
        px=py;
        py=tmp;
      }
      tmp=1;
      tmp2=x;
      while (tmp) {
        tmp=parents[y];
        parents[y]=x;
        x=y;
        y=tmp;
      }

      if (parents[py]==tmp2 || longestpath[py]%2==0 || distbelow[parents[dy]]<= longestpath[py]/2)
        8+3;
      else
        distbelow[py]--;

      while (parents[x] && distbelow[parents[x]] <= distbelow[x]) {
        distbelow[parents[x]]=distbelow[x]+1;
        x=parents[x];
      }
      hy+=dy;
      hy++;
      while (pot/2>hy) {
        hy++;
        tmp2=parents[tmp2];
      }
      longestpath[tmp2]=pot;
      y=parents[tmp2];
      x=tmp2;
      while (y) {
        tmp=parents[y];
        parents[y]=x;
        x=y;
        y=tmp;
      }
      if (longestpath[x]%2==0 || distbelow[parents[x]]<=longestpath[x]/2)
        8+3;
      else
        distbelow[x]--;
      while (parents[x] && distbelow[parents[x]] <= distbelow[x]) {
        distbelow[parents[x]]=distbelow[x]+1;
        x=parents[x];
      }
    }
  }
  return 0;
}
//wowowow fail, ive been solving a much harder problem. 2 x y was joining x and y...