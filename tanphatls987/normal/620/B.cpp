#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;
const int seg[10]={6,2,5,5,4,5,6,3,7,6};

int main(){
    int L,R;
    cin>>L>>R;
    int ans=0;
    FOR(i,L,R){
        int x=i;
        while (x){
            ans+=seg[x%10];
            x/=10;
        }
    }
    cout<<ans;
}