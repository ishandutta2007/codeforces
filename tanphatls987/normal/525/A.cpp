#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

int n,h[30];
string s;
int main(){
    cin>>n>>s;
    int ans=0;
    REP(i,0,n-1){
        h[s[2*i]-'a']++;
        int x=s[2*i+1]-'A';
        if (!h[x]) h[x]++,ans++;
        h[x]--;
    }
    cout<<ans;
}