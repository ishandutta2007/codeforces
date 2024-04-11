#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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

int n;
ii a[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    int ans=0;
    a[0].X=-inf-10,a[n+1].X=inf*2+10;
    for(int L=1,R=n;L<=R;L++,R--){
        //printf("%d %d\n",L,R);
        while (L<=R){
            if (a[L].X-a[L-1].X>a[L].Y) ans++;
            else if (a[L+1].X-a[L].X>a[L].Y){
                a[L].X+=a[L].Y;
                ans++;
            }else break;
            L++;
        }
        while (L<=R){
            if (a[R+1].X-a[R].X>a[R].Y) ans++;
            else if (a[R].X-a[R-1].X>a[R].Y){
                a[R].X-=a[R].Y;
                ans++;
            }else break;
            R--;
        }
    }
    cout<<ans;
}