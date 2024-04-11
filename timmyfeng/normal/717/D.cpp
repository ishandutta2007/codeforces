#include "bits/stdc++.h"
using namespace std;

#define pb push_back
typedef long double ld;
#define nl '\n'

const int N=30;
const int K=128;
int n, x;
ld f[N][K];
ld pr[K];
ld pr2[K];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> x;
    cout << fixed << setprecision(9);
    for(int i=0; i<=x; i++) cin >> f[0][i];

    for(int i=1; (1<<i)<=n; i++){
        for(int a=0; a<K; a++){
            for(int b=0; b<K; b++){
                f[i][a]+=f[i-1][b]*f[i-1][a^b];
            }
            // cout << "f[" << i << "][" << a << "] " << f[i][a] << nl;
        }
    }

    pr[0]=1;
    for(int k=0; k<30; k++){
        if(n&(1<<k)){
            for(int a=0; a<K; a++){
                for(int b=0; b<K; b++){
                    pr2[a]+=pr[b]*f[k][a^b];
                }
            }
            for(int a=0; a<K; a++){
                pr[a]=pr2[a];
                // cout << "pr " << a << " " << pr[a] << nl;
                pr2[a]=0;
            }
        }
    }
    cout << ld(1.0-pr[0]);
}

// P(xor x_i = 0) 
// dp[i][xor] =