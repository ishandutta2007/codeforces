#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9+10;
const int MOD=1e9+7;
const int N=5e5+10;

int n,m,q,l,r,x,type,add[1005];
ii a[N];
bool comp(ii a,ii b){
    if (a.X==b.X) return a.Y<b.Y;
    return a.X<b.X;
}
void modified(int l,int r,int x){
    l--,r--;
    ///1st block
    int L=l/m*m,R=min(L+m,n);
    REP(i,L,R) if (a[i].Y>=l&&a[i].Y<=r) a[i].X=min(a[i].X+x,inf);
    sort(a+L,a+R,comp);
    if (l/m==r/m) return;
    ///med block
    REP(i,l/m+1,r/m) add[i]=min(add[i]+x,inf);
    ///last block
    L=r/m*m,R=min(L+m,n);
    REP(i,L,R) if (a[i].Y>=l&&a[i].Y<=r) a[i].X=min(a[i].X+x,inf);
    sort(a+L,a+R,comp);
}
int main(){
    scanf("%d%d",&n,&q);
    REP(i,0,n) scanf("%d",&a[i].X);
    REP(i,0,n) a[i].Y=i;
    m=int(sqrt(n));
    for(int i=0;i*m<n;i++){
        int st=i*m,en=min(st+m,n);
        sort(a+st,a+en,comp);
    }
    while (q--){
        scanf("%d",&type);
        if (type==1){
            scanf("%d%d%d",&l,&r,&x);
            modified(l,r,x);
        }else{
            scanf("%d",&x);
            int L=n+1,R=n;
            for(int i=0;i*m<n;i++){
                int st=i*m,en=min(st+m,n);
                ii cur=ii(x-add[i],n);
                int pos=upper_bound(a+st,a+en,cur,comp)-a-1;
                if (pos>=st&&a[pos].X==cur.X) R=a[pos].Y;
                cur.X--;
                pos=upper_bound(a+st,a+en,cur,comp)-a;
                if (pos<en&&a[pos].X==cur.X+1) L=min(L,a[pos].Y);
            }
            printf("%d\n",R-L);
        }
//        REP(i,0,n) printf("%d %d\n",a[i].X+add[i/m],a[i].Y);
    }
}