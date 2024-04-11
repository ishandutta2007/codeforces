#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

const int maxn=2007;
int n,ans[maxn];
ll area[maxn],p[maxn];


ll q1(int a,int b,int c){
    cout<<1<<" "<<a<<" "<<b<<" "<<c<<endl;
    ll u;
    cin>>u;
    return u;
}

bool q2(int a,int b,int c){
    cout<<2<<" "<<a<<" "<<b<<" "<<c<<endl;
    int u;
    cin>>u;
    return u>0;
}

bool cmp(int u,int v){
    return area[u]<area[v];
}
int main(){
    cin>>n;
    int t0=2;
    for (int i=3;i<=n;++i){
        if (q2(1,t0,i)){
            t0=i;
        }
    }
    ans[1]=1,ans[2]=t0;
    for (int i=1;i<=n;++i){
        p[i]=i;
    }
    for (int i=2;i<=n;++i){
        if (i==t0) continue;
        area[i]=q1(1,t0,i);
    }
    sort(p+1,p+n+1,cmp);
    int l=3,r=n;
    for (int i=3;i<n;++i){
        if (!q2(1,p[i],p[i+1])){
            ans[l++]=p[i];
        }
        else{
            ans[r--]=p[i];
        }
    }
    ans[l]=p[n];
    printf("0 1 ");
    for (int i=n;i>1;--i){
        printf("%d ",ans[i]);
    }
    return 0;
}