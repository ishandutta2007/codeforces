#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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

ll a[2][N];
int p[N],n;
bool comp(int x,int y){
    return a[0][x]<a[0][y];
}
void prepare(){
    int xa,xb;
    scanf("%d%d%d",&n,&xa,&xb);
    int kx,bx;
    FOR(i,1,n){
        scanf("%d%d",&kx,&bx);
        a[0][i]=1LL*kx*xa+bx;
        a[1][i]=1LL*kx*xb+bx;
//        printf("->%lld %lld\n",a[0][i],a[1][i]);
    }
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,comp);
//    FOR(i,1,n) cout<<p[i]<<" \n"[i==n];
    int cur=n+1;
    a[0][n+1]=a[1][n+1]=ll(1e16);
    for(int en=n;en>=1;){
        int st=en;
        while (en>=1&&a[0][p[en]]==a[0][p[st]]) en--;
        FOR(i,en+1,st){
            if (a[1][p[i]]>a[1][cur]){
                printf("Yes");
                return;
            }
        }
        FOR(i,en+1,st) if (a[1][p[i]]<a[1][cur]) cur=p[i];
    }
    printf("No");
}
int main(){
    prepare();
}