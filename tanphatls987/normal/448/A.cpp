#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

#define X first
#define Y second
#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define ENDL printf("\n")
#define inf 1000000

const int N=100;

typedef long long ll;

int a1,a2,a3,b1,b2,b3,n;
int main()
{
    scanf("%d%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3,&n);
    if ((a1+a2+a3+4)/5+(b1+b2+b3+9)/10<=n) cout<<"YES";else cout<<"NO";
}