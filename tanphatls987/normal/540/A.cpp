#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("301.inp","r",stdin)
#define OUTPUT freopen("301.out","w",stdout)
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

int n;
string s1,s2;
int main(){
    cin>>n>>s1>>s2;
    int ans=0;
    REP(i,0,n){
        if (s1[i]<s2[i]) swap(s1[i],s2[i]);
        ans+=min(s1[i]-s2[i],'9'-s1[i]+1+s2[i]-'0');
    }
    cout<<ans;
}