//da se opet rodim ziveo bih isto
//spreman i na srecu ali i na tugu
//ne bih promenio nista
//jer ti ne bi bila ista
//a ja necu, necu ljubav drugu
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
int ri(){int x;scanf("%i",&x);return x;}
const int N=300050;
int odd,p[N],sz[N];
vector<int> bck;
int Find(int x){return x==p[x]?x:Find(p[x]);}
void Union(int x,int y){
    x=Find(x),y=Find(y);
    if(x==y)return;
    if(sz[x]>sz[y])swap(x,y);
    if((sz[x]&1)&&(sz[y]&1))odd-=2;
    bck.pb(x),p[x]=y,sz[y]+=sz[x];
}
void Undo(int las){
    while(bck.size()>las){
        int x=bck.back();
        bck.pop_back();
        int y=p[x];
        sz[y]-=sz[x],p[x]=x;
        if((sz[x]&1)&&(sz[y]&1))odd+=2;
    }
}
int u[N],v[N],w[N],ord[N],idx[N],ans[N];
void Add(int i){Union(u[i],v[i]);}
void Solve(int l,int r,int L,int R){
    if(l>r)return;
    int mid=l+r>>1;
    int las=bck.size();
    for(int i=l;i<=mid;i++)if(idx[i]<L)Add(i);
    ans[mid]=-1;
    for(int i=L;i<=R;i++){
        if(ord[i]<=mid)Add(ord[i]);
        if(odd==0){ans[mid]=i;break;}
    }
    Undo(las);
    if(ans[mid]==-1){
        for(int i=l;i<mid;i++)ans[i]=-1;
        las=bck.size();
        for(int i=l;i<=mid;i++)if(idx[i]<L)Add(i);
        Solve(mid+1,r,L,R);
        Undo(las);
    }else{
        las=bck.size();
        for(int i=L;i<ans[mid];i++)if(ord[i]<l)Add(ord[i]);
        Solve(l,mid-1,ans[mid],R);
        Undo(las);
        las=bck.size();
        for(int i=l;i<=mid;i++)if(idx[i]<L)Add(i);
        Solve(mid+1,r,L,ans[mid]);
        Undo(las);
    }
}
int main(){
    int n=ri(),m=ri();
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    odd=n;
    for(int i=1;i<=m;i++){
        u[i]=ri(),v[i]=ri(),w[i]=ri();
        ord[i]=i;
    }
    sort(ord+1,ord+1+m,[&](int i,int j){return w[i]<w[j];});
    for(int i=1;i<=m;i++)idx[ord[i]]=i;
    Solve(1,m,1,m);
    for(int i=1;i<=m;i++){
        if(ans[i]==-1)printf("-1\n");
        else printf("%i\n",w[ord[ans[i]]]);
    }
    return 0;
}