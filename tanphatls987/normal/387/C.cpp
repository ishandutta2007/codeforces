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
string s;

int main()
{
    cin>>s;
    int ans=0;
    FORD(i,s.length()-1,0)
    {
        int j=i;
        ans++;
        while (s[j]=='0') j--;
        if (i-j+1>j||i-j+1==j&&s[0]<s[j]) break;
        i=j;
    }
    cout<<ans;
}