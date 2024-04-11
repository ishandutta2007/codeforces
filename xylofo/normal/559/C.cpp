#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,b) FOR(i,0,b)
#define X first 
#define Y second
#define PB push_back
#define ALLOF(a) (a).begin(),(a).end()
#define MP make_pair

typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

LL MOD=1e9 + 7;

LL mul_inv(LL a, LL b){
    LL b0 = b, t, q;
    LL x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

LL fac[200005];

LL nCr(LL n, LL k){ //needs mod_inverse
    LL ans = fac[n];
    ans*= mul_inv(fac[k],MOD);
    ans%=MOD;
    ans*= mul_inv(fac[n-k],MOD);
    ans%=MOD;
    return ans;
}

VI X,Y;
VI DP;
LL solve(int n){
    if(n==X.size()-2){
        return -1;
    }
    if(DP[n]!=-1)return DP[n];
    LL ans=0;
    REP(i,X.size())if(i!=n){
        if(X[n]>=X[i] && Y[n]>=Y[i]){
            ans -= nCr(-X[i]+X[n] - Y[i]+Y[n],-X[i]+X[n]) * solve(i);
            ans%=MOD;
            ans+=MOD;
            ans%=MOD;
            // cout<<X[i]-X[n] + Y[i]-Y[n]<< "nCr" <<X[i]-X[n]<<endl;
        }
    }
    // cout<<X[n]<<" "<<Y[n]<<" "<<ans<<endl;
    return DP[n]=ans;
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    LL h,w,n;
    cin>>h>>w>>n; 
    X.resize(n+2);
    Y.resize(n+2);
    DP.resize(n+2,-1);
    X[n]=1;Y[n]=1;
    X[n+1]=h;Y[n+1]=w;
    fac[0]=1;
    FOR(i,1,200005){
        fac[i]=fac[i-1]*i;
        fac[i]%=MOD;
    }
    REP(i,n){
        cin>>X[i]>>Y[i];
    }
    cout<<solve(n+1)<<endl;
    return 0;
}