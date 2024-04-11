#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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

int n,x,y;
ll c;
ll cals(int M,int len){
    M-=len;
    if (M<0) return 0;
    return 1LL*(M+1)*(M+1);
}
ll calc(int M,int len){
    M-=len;
    if (M<0) return 0;
    return 1LL*(M+1)*(M+2)/2;
}
bool check(int M){
    ll sum=2LL*(M+1)*(M+1)-(2*M+1);
    sum-=cals(M,n-y+1)+cals(M,y)+cals(M,n-x+1)+cals(M,x)-calc(M,n-x+n-y+2)-calc(M,n-x+y+1)-calc(M,x+n-y+1)-calc(M,x+y);
//    cout<<M<<" "<<sum<<" "<<c<<'\n';
    return sum>=c;
}
int main(){
    cin>>n>>x>>y>>c;
    int L=0,R=n<<1;
    while (L<=R){
        int M=L+(R-L)/2;
        if (check(M)) R=M-1;
        else L=M+1;
    }
    cout<<L;
}