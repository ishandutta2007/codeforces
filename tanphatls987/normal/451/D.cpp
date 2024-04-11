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

const int N=100001;

typedef long long ll;

ll odd,even,o[2]={0},e[2]={0},last[2]={0};
string s;
int main()
{
    cin>>s;
    REP(i,0,s.length())
    {
        if ((i-last[s[i]-'a'])%2) swap(o[s[i]-'a'],e[s[i]-'a']);
        o[s[i]-'a']++;
        odd+=o[s[i]-'a'];
        even+=e[s[i]-'a'];
        last[s[i]-'a']=i;
    }
    cout<<even<<" "<<odd;
}