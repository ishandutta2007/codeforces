#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define ENDL printf("\n")
#define inf 1000000

const int N=1001;

typedef long long ll;

string s;
int v[30],k,n;
int prepare()
{
    cin>>s>>k;
    n=s.length();
    FOR(i,0,'z'-'a') cin>>v[i];
}
int solve()
{
    int ans=0;
    REP(i,0,n) ans+=v[s[i]-'a']*(i+1);
    int sel=*max_element(v,v+26);
    FOR(i,n+1,n+k) ans+=sel*i;
    cout<<ans;
}
int main()
{
    prepare();
    solve();
}