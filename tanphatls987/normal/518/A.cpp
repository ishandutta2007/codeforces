#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=0;

string s1,s2;
string solve(){
    int n=s1.length();
    while (s1[n-1]=='z'&&n) s1[n-1]='a',n--;
    if (n==0) return "No such string";
    s1[n-1]++;
    if (s1>=s2) return "No such string";
    return s1;
}
int main(){
    cin>>s1>>s2;
    cout<<solve();
}