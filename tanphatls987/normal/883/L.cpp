#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> lli;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=2e5+10;

const int inf=1e9+10;
const ll linf=4e18;

int n,m,test;


int a[N];
int spot[N];

struct comp{
  bool operator ()(const lli& a,const lli& b){
    if (a.X!=b.X) return a.X>b.X;
    return a.Y>b.Y;
  }
};
bool cmp(lli a,lli b){
  if (a.X!=b.X) return a.X<b.X;
  return a.Y<b.Y;
}

priority_queue <lli,vector<lli>,comp> pq[N];


multiset <int> pos;
set <lli> imp_mo;

ll gloti;

void prepare(){
    cin>>n>>m>>test;
    for(int i=1;i<=m;i++) cin>>a[i];
    pos.insert(-inf);
    pos.insert(inf);

    for(int i=1;i<=m;i++){
        pos.insert(a[i]);
        pq[a[i]].push(lli(0,i));
        spot[i]=a[i];
    }
    gloti=0;
}

void solve(ll ti,int st,int en){
    ll ava_ti=max(ti,gloti);
    if (int(imp_mo.size())==m)
        ava_ti=max(ava_ti,imp_mo.begin()->X);
    while (!imp_mo.empty()&&imp_mo.begin()->X<=ava_ti){
        lli cur=*imp_mo.begin();
        imp_mo.erase(cur);
        pq[spot[cur.Y]].push(cur);
        pos.insert(spot[cur.Y]);
    }
    auto iteL=pos.lower_bound(st);
    auto iteR=iteL;--iteL;
    int dist=min(abs((*iteL)-st),abs((*iteR)-st));
    lli ans=lli(linf,0);
    if (abs((*iteL)-st)==dist){
        lli vL=pq[*iteL].top();
        ans=min(ans,vL,cmp);
    }
    if (abs((*iteR)-st)==dist){
        lli vR=pq[*iteR].top();
        ans=min(ans,vR,cmp);
    }
    ll ansc=ans.Y,anst=ava_ti-ti+dist;
    cout<<ansc<<" "<<anst<<'\n';
    ///add event
    pq[spot[ansc]].pop();
    pos.erase(pos.find(spot[ansc]));
    spot[ansc]=en;
    imp_mo.insert(lli(ava_ti+dist+abs(en-st),ansc));
    gloti=ava_ti;
}
int main(){
    prepare();
    while (test--){
        ll ti;
        int st,en;
        cin>>ti>>st>>en;
        solve(ti,st,en);
    }
}