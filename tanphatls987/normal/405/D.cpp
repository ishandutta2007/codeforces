#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=1e6;

int n,x,h[N+5];
int main(){
    scanf("%d",&n);
    while (n--){
        scanf("%d",&x);
        h[x]=1;
    }
    vector <int> ans;
    int c=0;
    FOR(i,1,N>>1) {
        if (h[i]&&h[N-i+1]) c++;
        else if (h[i]) ans.push_back(N-i+1);
        else if (h[N-i+1]) ans.push_back(i);
    }
    FOR(i,1,N>>1) if (!h[i]&&!h[N-i+1]&&c){
        c--;
        ans.push_back(i);
        ans.push_back(N-i+1);
    }
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d ",i);
}