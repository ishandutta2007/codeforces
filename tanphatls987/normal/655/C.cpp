#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e5+10;

int n,k;
string s;
int psum[N];

bool check(int mid){
    FOR(i,1,n) if (s[i-1]=='0'&&psum[min(i+mid,n)]-psum[max(i-mid-1,0)]>k) {
//        cout<<mid<<" "<<i<<'\n';
        return 1;
    }
    return 0;
}
int solve(){
    FOR(i,1,n) psum[i]=psum[i-1]+(s[i-1]=='0');
    int L=0,R=n;
    while (L<=R){
        int mid=(L+R)/2;
        if (check(mid)) R=mid-1;
        else L=mid+1;
    }
    return L;
}
int main(){
//    freopen("input.inp","r",stdin);
    cin>>n>>k>>s;
    cout<<solve();
}