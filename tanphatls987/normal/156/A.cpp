#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length(),ans=m;
    REP(st,-m+1,n){
        int cur=0;
        REP(j,0,m) if (st+j<0||st+j>=n||s1[st+j]!=s2[j]) cur++;
        ans=min(ans,cur);
    }
    cout<<ans;
}