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

int a[13],n;
void prepare(){
    cin>>n;
    FOR(i,1,12) cin>>a[i];
    sort(a+1,a+13);
}
int main()
{
    prepare();
    FORD(i,12,0) {if (n<=0) {cout<<12-i;return 0;};n-=a[i];}
    cout<<-1;
}