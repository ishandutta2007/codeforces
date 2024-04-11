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

const int N=110;

typedef long long ll;
string s,t;
int n,m,h1[N],h2[N],ar,au,both;
int solve()
{
    ar=0;au=0;both=0;
    if (n>=m)
    {
        ar=1;
        REP(i,0,n) h1[s[i]-'a']++;
        REP(i,0,m) h2[t[i]-'a']++;
        FOR(i,0,'z'-'a') if (h1[i]<h2[i]) ar=0;
        au=0;
        int j=0;
        FOR(i,0,n) if (s[i]==t[j]&&j<m) j++;
        if (j==m) au=1;
        if (n!=m&&ar==1&&au==0) both=1;
        if (n!=m) ar=0;
    }
    if (ar) {cout<<"array";return 0;}
    if (au) {cout<< "automaton";return 0;}
    if (both) {cout<<"both";return 0;}
    cout<<"need tree";
}
int main()
{
    cin>>s>>t;
    n=s.length();m=t.length();
    solve();
}