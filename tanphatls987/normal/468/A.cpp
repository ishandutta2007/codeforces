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

const int MOD=1000000007;
const int N=0;

typedef long long ll;

int n;
void solve(){
    if (n<4) {printf("NO");return;}
    printf("YES\n");
    if (n%2==0){
        printf("4 * 2 = 8\n8 * 3 = 24\n24 * 1 = 24\n");
        for(int i=5;i<n;i+=2) printf("%d - %d = 1\n1 * 24 = 24\n",i+1,i);
    }else{
        printf("5 - 1 = 4\n4 - 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
        for(int i=6;i<n;i+=2) printf("%d - %d = 1\n1 * 24 = 24\n",i+1,i);
    }
}
int main()
{
    cin>>n;
    solve();
}