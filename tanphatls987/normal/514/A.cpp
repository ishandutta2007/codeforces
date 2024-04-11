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

string s;
int main(){
    cin>>s;
    int n=s.length();
    if (s[0]-'0'>4&&s[0]!='9') s[0]='9'-s[0]+'0';
    REP(i,1,n) if (s[i]-'0'>4) s[i]='9'-s[i]+'0';
    cout<<s;
}