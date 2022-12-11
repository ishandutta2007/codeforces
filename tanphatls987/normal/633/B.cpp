#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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

int main(){
    int n;
    cin>>n;
    int sum=0,st=0;
    while (sum<n){
        st+=5;
        int tmp=st;
        while (tmp%5==0) sum++,tmp/=5;
    }
    if (sum==n){
        cout<<"5\n";
        FOR(i,0,4) cout<<st+i<<" ";
    }else cout<<"0";
}