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
const int N=1e3+10;


int n,h[N];
int main(){
    cin>>n;
    vector <int> ans;
    FOR(i,2,n) if (!h[i]){
        int cur=1;
        while (1LL*cur*i<=n) {
            cur*=i;
            ans.push_back(cur);
        }
        for(int j=i+i;j<=n;j+=i) h[j]=1;
    }
    printf("%d\n",ans.size());
    for(auto x:ans) printf("%d ",x);
}