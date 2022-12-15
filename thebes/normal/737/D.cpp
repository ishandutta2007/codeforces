#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 4004;
int dp[MN][90][90], n, i, psa[MN], vs[MN][90][90];

int solve(int l,int r,int k){
    if(r-l+1<k) return 0;
    else if(vs[l][n-r-l][k]) return dp[l][n-r-l][k];
    vs[l][n-r-l][k] = 1;
    int res=-1<<30;
    for(int i=0;i<2;i++){
        int nl = l+k+i-1;
        if(nl>r) continue;
        int sm = psa[nl]-psa[l-1];
        int g = 1<<30;
        for(int j=0;j<2;j++){
            int nr = r-k-i-j+1;
            if(nr<=nl) continue;
            int ms = psa[r]-psa[nr-1];
            g = min(g, -ms+solve(nl+1,nr-1,k+i+j));
        }
        if(g==1<<30) g = 0;
        res = max(res, sm+g);
    }
    dp[l][n-r-l][k] = res;
    return res;
}

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&psa[i]), psa[i]+=psa[i-1];
    printf("%d\n",solve(1,n,1));
    return 0;
}