#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 0

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

const ll inf=1e15;
const int MOD=1e9+7;
const int N=1e5+10;

int n,x,y,w,h[N],s[N],top,q,root;
vector <ii> a[N];
ll len,small,old,t[N],d[3][N];
void DFS(int par,int x,ll* d){
    for(auto i:a[x]) if (i.Y!=par){
        d[i.Y]=d[x]+i.X;
        DFS(x,i.Y,d);
    }
}
void prepare(){
    scanf("%d",&n);
    FOR(i,2,n) {
        scanf("%d%d%d",&x,&y,&w);
        a[x].push_back(ii(w,y));
        a[y].push_back(ii(w,x));
    }
    DFS(0,1,d[0]);
    FOR(j,0,1){
        ll ma=*max_element(d[j]+1,d[j]+n+1);
        FOR(i,1,n) if (d[j][i]==ma){
            DFS(0,i,d[j+1]);
            break;
        }
    }
    FOR(i,1,n) t[i]=max(d[1][i],d[2][i]);
    root=0;
    small=*min_element(t+1,t+n+1);
    FOR(i,1,n) if (t[i]==small) root=i;
    //old=t[root];
    t[0]=inf;
}
void DP(int par,int x){
    s[++top]=x;
    int L=1,R=top;
    h[x]=1;
    while (L<=R){
        int M=(L+R)/2;
        if (t[x]-t[s[M]]<=len) R=M-1;
        else L=M+1;
    }
    if (debug){
        printf("%d %d %d\nS:",x,R,top);
        FOR(i,1,top) cout<<s[i]<<" \n"[i==top];
    }
    h[s[R]]--;
    for(auto i:a[x]) if (i.Y!=par){
        DP(x,i.Y);
        h[x]+=h[i.Y];
    }
    top--;
}
int main(){
    if (debug) INPUT;
    prepare();
    if (debug){
        FOR(i,1,n) cout<<t[i]<<" \n"[i==n];
        cout<<root<<'\n';
    }
    scanf("%d",&q);
    while (q--){
        scanf("%lld",&len);
        memset(h,0,sizeof(h));
        top=0;
        int ans=0;
        DP(0,root);
        ans=max(ans,*max_element(h+1,h+n+1));
        //if (debug) FOR(i,1,n) cout<<h[i]<<" \n"[i==n];
        printf("%d\n",ans);
    }
}