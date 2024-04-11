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


const int maxn=200007;
int C[maxn],n,ans[maxn],a[maxn],p[maxn];
vector<PI> q[maxn];
int lowbit(int u){
    return u&(-u);
}

void update(int x,int val){
    for (int i=x;i<=n;i+=lowbit(i)){
        C[i]+=val;
    }
}

int query(int x){
    int ans=0;
    for (int i=x;i>0;i-=lowbit(i)){
        ans+=C[i];
    }
    return ans;
}

int mid_search(int l,int r,int val){
    if (l==r) return l;
    int md=(l+r)>>1;
    if (query(md)<val) return mid_search(md+1,r,val);
    else return mid_search(l,md,val);
}

bool cmp(int u,int v){
    if (a[u]>a[v]) return 1;
    else if (a[u]==a[v]&&u<v) return 1;
    return 0;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        p[i]=i;
    }    
    sort(p+1,p+n+1,cmp);
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        q[u].push_back({v,i});
    }
    for (int i=1;i<=n;++i){
        update(p[i],1);
        for (auto c:q[i]){
            ans[c.S]=mid_search(1,n,c.F);
        }
    }
    for (int i=1;i<=m;++i){
        printf("%d\n",a[ans[i]]);
    }
    return 0;
}