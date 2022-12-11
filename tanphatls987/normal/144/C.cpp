#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int alp=26;

int h[alp];
string s1,s2;
int solve(){
    for(auto i:s2) h[i-'a']++;
    int n=s1.length(),m=s2.length();
    int ans=0;
    FOR(i,1,n){
        if (s1[i-1]!='?') h[s1[i-1]-'a']--;
        if (i>=m){
            bool nok=1;
            REP(i,0,alp) if (h[i]<0) nok=0;
            ans+=nok;
            if (s1[i-m]!='?') h[s1[i-m]-'a']++;
        }
    }
    return ans;
}
int main(){
    cin>>s1>>s2;
    cout<<solve();
}