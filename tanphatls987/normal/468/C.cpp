#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

typedef long long ll;
const int MOD=1000000007;
const ll N=1e18;

ll n,f[19]={0};
int main(){
    cin>>n;
    ll po=1;
    FOR(i,1,18){
        f[i]=((10*f[i-1])%n+(po*45)%n)%n;
        po=(po*10)%n;
    }
    f[18]=(f[18]+1)%n;
    cout<<n-f[18]+1<<" "<<N+n-f[18];
}