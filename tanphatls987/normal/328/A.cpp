#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","r",stdout)
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
const int N=0;

int a[4];
bool arit(){
    int d=a[1]-a[0];
    FOR(i,2,3) if (a[i]-a[i-1]!=d) return false;
    printf("%d",a[3]+d);
    return true;
}
bool geo(){
    int v=__gcd(a[1],a[0]),x=a[1]/v,y=a[0]/v;
    FOR(i,2,3){
        int cv=__gcd(a[i],a[i-1]),cx=a[i]/cv,cy=a[i-1]/cv;
        if (cx*y!=cy*x) return false;
    }
    if (((a[3]*x)%y)==0) printf("%d",(a[3]*x)/y);else return false;
    return true;
}
int main(){
    FOR(i,0,3) cin>>a[i];
    if (arit()) return 0;
    if (geo()) return 0;
    printf("42");
}