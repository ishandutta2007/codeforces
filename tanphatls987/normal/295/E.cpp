#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("tmp.inp","r",stdin)
#define OUTPUT freopen("tmp.out","w",stdout)
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

int n,m,n1,cord[N],p[N<<1],cur[N],q[N][3];
struct info{
    int c;
    ll sum,ans;
    info (int _c=0,ll _sum=0,ll _ans=0){
        c=_c;
        sum=_sum;
        ans=_ans;
    }
}b[N<<3];
info merge(info a,info b){
    return info(a.c+b.c,a.sum+b.sum,a.ans+b.ans+a.c*b.sum-b.c*a.sum);
}
void update(int node,int L,int R,int x,int v){
    if (p[L]>cord[x]||p[R]<cord[x]) return;
    if (L==R){
        if (v==1) b[node]=info(1,cord[x],0);
        else b[node]=info();
        return;
    }
    update(node*2,L,(L+R)/2,x,v);
    update(node*2+1,(L+R)/2+1,R,x,v);
    b[node]=merge(b[node*2],b[node*2+1]);
}
info get(int node,int L,int R,int l,int r){
    if (L>r||R<l) return info();
    if (l<=L&&R<=r) return b[node];
    return merge(get(node*2,L,(L+R)/2,l,r),get(node*2+1,(L+R)/2+1,R,l,r));
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",cord+i);
    n1=n;
    FOR(i,1,n) p[i]=cur[i]=cord[i];
    scanf("%d",&m);
    FOR(i,1,m){
        FOR(j,0,2) scanf("%d",q[i]+j);
        if (q[i][0]==1){
            cur[q[i][1]]+=q[i][2];
            p[++n1]=cur[q[i][1]];
        }
    }
    sort(p+1,p+n1+1);
    n1=unique(p+1,p+n1+1)-p-1;
//    FOR(i,1,n1) printf("%d ",p[i]);ENDL;
    FOR(i,1,n) update(1,1,n1,i,1);
}
void check(int node,int L,int R){
    printf("%d %d %d %d %lld\n",node,L,R,b[node].c,b[node].sum);
    if (L<R){
        check(node*2,L,(L+R)/2);
        check(node*2+1,(L+R)/2+1,R);
    }
}
void solve(){
//    check(1,1,n1);
    FOR(i,1,m){
        if (q[i][0]==1){
            update(1,1,n1,q[i][1],-1);
            cord[q[i][1]]+=q[i][2];
            update(1,1,n1,q[i][1],1);
//            printf("%d\n",i);
//            check(1,1,n1);
        }else {
            int L=lower_bound(p+1,p+n1+1,q[i][1])-p,R=upper_bound(p+1,p+n1+1,q[i][2])-p-1;
//            printf("%d %d ",L,R);
            printf("%I64d\n",get(1,1,n1,L,R).ans);
        }
    }
}
int main(){
//    INPUT;
    prepare();
    solve();
}