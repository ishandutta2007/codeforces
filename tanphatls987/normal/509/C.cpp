#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e3+10,M=1e3;

int n,x,f[N],a[N]={0};
int main(){
    scanf("%d",&n);
    FOR(t,1,n){
        scanf("%d",&x);
        FORD(j,M,0) f[j]=f[j+1]+a[j];
        FOR(j,0,M){
            if (a[j]==9) continue;
            if (x>=f[j]+1&&x-f[j+1]<=9*(j+1)){
                a[j]=max(a[j]+1,x-f[j+1]-9*j);
                x-=f[j+1]+a[j];
                REP(i,0,j) a[i]=min(9,x),x-=a[i];
                break;
            }
        }
        int m=M;
        while (a[m]==0) m--;
        FORD(i,m,0) cout<<a[i];
        ENDL;
    }
}