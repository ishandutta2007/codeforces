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
#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int N=0;
const char* p[8]={"vaporeon", "jolteon", "flareon","umbreon", "leafeon", "glaceon", "sylveon","espeon"};

typedef long long ll;
bool a[8];
int n;
char s[10];
int main()
{
    cin>>n>>s;
    if (n==6)
    {
        printf("%s",p[7]);
        return 0;
    }
    if (n==8) {printf("%s",p[0]);return 0;}
    FOR(i,1,6) a[i]=true;
    REP(i,0,n) if (s[i]!='.') FOR(j,1,6) if (s[i]!=p[j][i]) a[j]=false;
    FOR(i,1,6) if (a[i]) {printf("%s",p[i]);break;}
}