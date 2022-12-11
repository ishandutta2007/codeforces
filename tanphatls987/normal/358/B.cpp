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

string a,s;
int n;
void prepare()
{
    a="<3";
    cin>>n;
    FOR(i,1,n) cin>>s,a+=s+"<3";
    cin>>s;
}
int main()
{
    prepare();
    int j=0;
    n=a.length();
    for(int i=0;i<s.length()&&j<n;i++) if (a[j]==s[i]) j++;
    if (j==n) cout<<"yes";else cout<<"no";
}