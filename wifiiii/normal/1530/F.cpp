#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("branch-target-load-optimize")

#include<bits/stdc++.h>
using namespace std;
#define ll int

const int mod = 31607;
const int maxn = 50005;
int inv[maxn], bit[1<<21];
int mmc[1<<21][21];
ll dp[22];
int main() {
    dp[0]=1;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    inv[1]=1; for(int i=2;i<mod;++i) inv[i]=(mod-(mod/i))*inv[mod%i]%mod;
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    vector<ll> mr(n, 1), mc(n, 1);
    for(int i = 0; i < 1 << n; ++i) bit[i] = bit[i>>1] + (i&1);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
//            a[i][j] = 5000;
            cin >> a[i][j];
            a[i][j] = a[i][j] * inv[10000] % mod;
            mr[i] = mr[i] * a[i][j] % mod;
            mc[j] = mc[j] * a[i][j] % mod;
        }
    }
    for(int i=0;i<1<<n;++i) for(int j=0;j<n;++j) mmc[i][j]=1;
    for(int i=0;i<1<<n;++i) {
        for(int j=0;j<n;++j) {
            if(i>>j&1) {
                for(int k=0;k<n;++k) {
                    mmc[i][k]=mmc[i][k]*a[j][k]%mod;
                }
            }
        }
    }
    long long ans = 1;
    for(int i = 0; i < 1 << n; ++i) {
        ll tmp = 1;
        for(int j = 0; j < n; ++j) {
            if(i >> j & 1) tmp = tmp * mr[j] % mod;
        }
        for(int j = 0; j < n; ++j) {
            mc[j] = mc[j] * inv[mmc[i][j]] % mod;
        }
        for(int i=1;i<=n;++i) dp[i]=0;
        for(int j=0;j<n;++j) {
            for(int i=j+1;i>=1;--i) {
                (dp[i]+=dp[i-1]*mc[j])%=mod;
            }
        }
        for(int j=0;j<=n;++j) {
            if((j + bit[i]) & 1) ans += dp[j] * tmp % mod;
            else ans -= dp[j] * tmp % mod;
        }
        for(int j = 0; j < n; ++j) {
            mc[j] = mc[j] * mmc[i][j] % mod;
        }
    }

    {
        ll d1 = 1;
        long long tmp2 = 0;
        for(int i = 0; i < n; ++i) {
            mr[i] = mr[i] * inv[a[i][i]] % mod;
            mc[i] = mc[i] * inv[a[i][i]] % mod;
            d1 = d1 * a[i][i] % mod;
        }
        for(int i = 0; i < 1 << n; ++i) {
            ll tmp = 1;
            for(int j = 0; j < n; ++j) {
                if(i >> j & 1) {
                    tmp = tmp * mr[j] % mod;
                    mmc[i][j] = mmc[i][j] * inv[a[j][j]] % mod;
                }
            }
            for(int j = 0; j < n; ++j) {
                mc[j] = mc[j] * inv[mmc[i][j]] % mod;
            }
            for(int i=1;i<=n;++i) dp[i]=0;
            for(int j=0;j<n;++j) {
                for(int i=j+1;i>=1;--i) {
                    (dp[i] += dp[i-1] * mc[j]) %= mod;
                }
            }
            for(int j = 0; j <= n; ++j) {
                if((j + bit[i]) & 1) tmp2 -= dp[j] * tmp % mod;
                else tmp2 += dp[j] * tmp % mod;
            }
            for(int j = 0; j < n; ++j) {
                mc[j] = mc[j] * mmc[i][j] % mod;
            }
            for(int j = 0; j < n; ++j) {
                if(i >> j & 1) {
                    mmc[i][j] = mmc[i][j] * a[j][j] % mod;
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            mr[i] = mr[i] * a[i][i] % mod;
            mc[i] = mc[i] * a[i][i] % mod;
        }
        ans += tmp2 * d1 % mod;
    }

    {
        ll d2 = 1; long long tmp2 = 0;
        for(int i = 0; i < n; ++i) {
            mr[i] = mr[i] * inv[a[i][n-1-i]] % mod;
            mc[n-1-i] = mc[n-1-i] * inv[a[i][n-1-i]] % mod;
            d2 = d2 * a[i][n-1-i] % mod;
        }
        for(int i = 0; i < 1 << n; ++i) {
            ll tmp = 1;
            vector<ll> del(n, 1);
            for(int j = 0; j < n; ++j) {
                if(i >> j & 1) {
                    tmp = tmp * mr[j] % mod;
                    for(int k = 0; k < n; ++k) {
                        if(j + k + 1 != n) del[k] = del[k] * a[j][k] % mod;
                    }
                }
            }
            for(int j = 0; j < n; ++j) {
                mc[j] = mc[j] * inv[del[j]] % mod;
            }
            for(int i=1;i<=n;++i) dp[i]=0;
            for(int j=0;j<n;++j) {
                for(int i=j+1;i>=1;--i) {
                    (dp[i]+=dp[i-1]*mc[j]) %= mod;
                }
            }
            for(int j = 0; j <= n; ++j) {
                if((j + bit[i]) & 1) tmp2 -= dp[j] * tmp % mod;
                else tmp2 += dp[j] * tmp % mod;
            }
            for(int j = 0; j < n; ++j) {
                mc[j] = mc[j] * del[j] % mod;
            }
        }
        for(int i = 0; i < n; ++i) {
            mr[i] = mr[i] * a[i][n-1-i] % mod;
            mc[n-1-i] = mc[n-1-i] * a[i][n-1-i] % mod;
        }
        ans += tmp2 * d2 % mod;
    }

    {
        ll d3 = 1;
        long long tmp2 = 0;
        for(int i = 0; i < n; ++i) {
            mr[i] = mr[i] * inv[a[i][n-1-i]] % mod;
            mc[n-1-i] = mc[n-1-i] * inv[a[i][n-1-i]] % mod;
            d3 = d3 * a[i][n-1-i] % mod;
            if(i != n - 1 - i) {
                mr[i] = mr[i] * inv[a[i][i]] % mod;
                mc[i] = mc[i] * inv[a[i][i]] % mod;
                d3 = d3 * a[i][i] % mod;
            }
        }
        for(int i = 0; i < 1 << n; ++i) {
            ll tmp = 1;
            vector<ll> del(n, 1);
            for(int j = 0; j < n; ++j) {
                if(i >> j & 1) {
                    tmp = tmp * mr[j] % mod;
                    for(int k = 0; k < n; ++k) {
                        if(j + k + 1 != n && j != k) del[k] = del[k] * a[j][k] % mod;
                    }
                }
            }
            for(int j = 0; j < n; ++j) {
                mc[j] = mc[j] * inv[del[j]] % mod;
            }
            for(int i=1;i<=n;++i) dp[i]=0;
            for(int j=0;j<n;++j) {
                for(int i=j+1;i>=1;--i) {
                    (dp[i]+=dp[i-1]*mc[j])%=mod;
                }
            }
            for(int j = 0; j <= n; ++j) {
                if((j + bit[i]) & 1) tmp2 += dp[j] * tmp % mod;
                else tmp2 -= dp[j] * tmp % mod;
            }
            for(int j = 0; j < n; ++j) {
                mc[j] = mc[j] * del[j] % mod;
            }
        }
        ans += tmp2 * d3 % mod;
    }
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << '\n';
}