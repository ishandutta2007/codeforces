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

typedef long long ll;
typedef pair<int,int> ii;

const int inf=((1LL<<31)-1);
const int MOD=1e9+7;
const int N=1e6+10;

int h[N]={0},n;
void erathos(){
    FOR(i,2,n) if (!h[i]) {
        for(int j=i+i;j<=n;j+=i) h[j]=1;
    }
}
int main(){
    cin>>n;
    erathos();
    FOR(i,2,n) if (h[i]&&h[n-i]) {cout<<i<<" "<<n-i;return 0;}
}