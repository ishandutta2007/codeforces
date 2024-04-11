#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,m,x,y,a[N],last[N],L[N],b[N<<2],ans[N],bi[N];
vector <int> p[N];
vector <ii> q[N];
void update(int node,int L,int R,int M,int v){
    if (L>M||R<M) return ;
    if (L==R){
        b[node]=v;
        return;
    }
    update(node*2,L,(L+R)/2,M,v);
    update(node*2+1,(L+R)/2+1,R,M,v);
    b[node]=min(b[node*2],b[node*2+1]);
}
int get(int node,int L,int R,int l,int r){
    if (L>r||R<l) return n+1;
    if (l<=L&&R<=r) return b[node];
    return min(get(node*2,L,(L+R)/2,l,r),get(node*2+1,(L+R)/2+1,R,l,r));
}
void add(int x,int v){
    while (x<=n){
        bi[x]+=v;
        x+=x&-x;
    }
}
int bget(int x){
    int ans=0;
    while (x){
        ans+=bi[x];
        x-=x&-x;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",a+i);
        p[a[i]].push_back(i);
    }
    //FOR(i,1,n) link[i]=link[i-1]+(a[i]!=a[i+1]);
    REP(t,1,N){
        int m1=p[t].size();
        FORD(i,m1-1,1){
            int j=i;
            while (j>1&&p[t][j-1]-p[t][j-2]==p[t][i]-p[t][i-1]) j--;
            FOR(k,j,i) L[p[t][k]]=(j>=2)?p[t][j-2]+1:0;
            i=j;
        }
        if (m1) L[p[t][0]]=0;
    }
    scanf("%d",&m);
    FOR(t,1,m){
        scanf("%d%d",&x,&y);
        q[y].push_back(ii(x,t));
    }
    FOR(i,1,n){
        if (last[a[i]]) {
            update(1,1,n,last[a[i]],n+1);
            add(last[a[i]],-1);
        }
        last[a[i]]=i;
        add(i,1);
        update(1,1,n,i,L[i]);
        for(auto j:q[i]){
            int x=j.X,c=bget(i)-bget(x-1);
            ans[j.Y]=c+(get(1,1,n,x,i)>x);
            //printf("%d %d %d %d %d\n",j.Y,x,i,c,get(1,1,n,x,i));
        }
    }
    FOR(i,1,m) printf("%d\n",ans[i]);
}