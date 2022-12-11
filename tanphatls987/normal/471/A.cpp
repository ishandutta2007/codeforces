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
const int N=110;

int a[N],h[N];
int main()
{
    FOR(i,1,6) cin>>a[i];
    FOR(i,1,6) h[a[i]]++;
    FOR(i,1,9) if (h[i]>=4)
    {
        if (h[i]==6) {printf("Elephant");return 0;}
        FOR(k,1,9) if (k!=i)
        {
            if (h[k]==2) {printf("Elephant");return 0;}
            if (h[k]==1) {printf("Bear");return 0;}
        }
    }
    printf("Alien");
}