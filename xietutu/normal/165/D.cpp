#include <cstdio>
#include <vector>
#include <algorithm> 
using namespace std;
const int INF=100004;
int dd[100001],p[100001][2],g[100001][2],n,m,x,y,root,j,k,t,tt,mmax;
long long ans;
bool f[100001];
vector<int> a[100001];
vector<long long> d[100001];
vector<int>::iterator it;
void add(int j,int k,int t) {
    while (k<d[j].size()) {
        d[j][k]+=t;
        k+=k&(-k);
    }
}
inline long long get(int j,int k) {
    long long s=0;
    while (k>0) {
        s+=d[j][k];
        k-=k&(-k);
    }
    return(s);
}
void go(int x) {
    vector<int>::iterator ite;
    for (ite=a[x].begin();ite!=a[x].end();++ite) 
        if (p[*ite][0]==0) {
            ++k;p[*ite][0]=j;p[*ite][1]=k;d[j].push_back(0);
            go(*ite);
        }
}
int main() {
    scanf("%d",&n);
    for (int i=1;i!=n;++i) {
        scanf("%d%d",&x,&y);
        g[i][0]=x;g[i][1]=y;
        ++dd[x];++dd[y];
        a[x].push_back(y);a[y].push_back(x);
    }
    for (int i=1;i!=n;++i) 
        if (dd[i]>mmax) {mmax=dd[i];root=i;}
    j=0;
    p[root][0]=INF;
    for (it=a[root].begin();it!=a[root].end();++it) {
        p[*it][0]=++j;p[*it][1]=k=1;
        d[j].push_back(0);d[j].push_back(0);
        go(*it);
        for (int i=1;i<=k;++i) add(j,i,1);
    } 
    scanf("%d",&m);
    for (int i=0;i!=m;++i) {
        scanf("%d",&t);
        switch (t) {
            case 1:
                scanf("%d",&tt);
                if (f[tt]) {
                  x=g[tt][0];y=g[tt][1];
                  if (x!=root&&y!=root) 
                    add(p[x][0],max(p[x][1],p[y][1]),-INF);
                  else if (x==root) 
                    add(p[y][0],p[y][1],-INF);
                  else if (y==root)
                    add(p[x][0],p[x][1],-INF);  
                  f[tt]=false;
                }
                break;
            case 2:
                scanf("%d",&tt);
                if (!f[tt]) {
                  x=g[tt][0];y=g[tt][1];
                  if (x!=root&&y!=root) 
                    add(p[x][0],max(p[x][1],p[y][1]),INF);
                  else if (x==root) 
                    add(p[y][0],p[y][1],INF);
                  else if (y==root)
                    add(p[x][0],p[x][1],INF);
                  f[tt]=true;
                }
                break;
            case 3:
                scanf("%d%d",&x,&y);
                if (x!=root&&y!=root) {
                  if (p[x][0]!=p[y][0]) 
                    ans=get(p[x][0],p[x][1])+get(p[y][0],p[y][1]);
                  else ans=get(p[x][0],max(p[x][1],p[y][1]))-get(p[x][0],min(p[x][1],p[y][1]));
                }
                else if (x==root) 
                    ans=get(p[y][0],p[y][1]);
                else if (y==root)
                    ans=get(p[x][0],p[x][1]);
                if (ans>=INF) printf("-1\n");
                  else printf("%d\n",ans);
                break;
        }
    }         
}