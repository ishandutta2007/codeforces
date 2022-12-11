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

typedef long long ll;

int n,k;
string s;
bool check(int x){
    if (x==n) return true;
    REP(i,s[x]+1,'a'+k) if (i!=s[x-1]&&i!=s[x-2]){
        s[x]=i;
        if (check(x+1)) return true;
    }
    return false;
}
void solve()
{
    FORD(i,n-1,0){
        if (check(i)) {cout<<s;return;}
        s[i]='a'-1;
    }
    cout<<"NO";
}
int main()
{
    cin>>n>>k>>s;
    solve();
}