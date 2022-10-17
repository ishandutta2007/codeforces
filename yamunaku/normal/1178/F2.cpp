//
// Created by yamunaku on 2019/07/14.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

class Solver{
private:
    int n,m;
    vector<int> a;
    vector<int> lx,rx;

    struct seg{
        int x;
        int l;
        int r;
    };

    ll dfs(int l, int r, int p){
        vector<seg> s;
        ll ans=1;
        int now=l;
        while(now<r){
            if(a[now]==p){
                now++;
                int sz=s.size();
                if(sz>0){
                    vector<vector<ll>> dp(sz + 1, vector<ll>(sz + 1, 0));
                    rep(i, sz){
                        if(s[i].r-s[i].l>=3){
                            ans = ans*dfs(s[i].l + 1, s[i].r - 1, s[i].x)%MOD9;
                        }
                        dp[i][i+1]=1;
                        dp[i][i] = 1;
                    }
                    dp[sz][sz] = 1;
                    repl(w, 2, sz + 1){
                        rep(i, sz - w + 1){
                            int l = i, r = i + w;
                            int mi = IINF;
                            int idx = -1;
                            repl(k, l, r){
                                if(mi > s[k].x){
                                    mi = s[k].x;
                                    idx = k;
                                }
                            }
                            ll suml = 0, sumr = 0;
                            repl(x, l, idx + 1){
                                suml = (suml + dp[l][x] * dp[x][idx] % MOD9) % MOD9;
                            }
                            repl(x, idx + 1, r + 1){
                                sumr = (sumr + dp[idx + 1][x] * dp[x][r] % MOD9) % MOD9;
                            }
                            dp[l][r] = suml * sumr % MOD9;
                        }
                    }
                    ans = ans * dp[0][sz] % MOD9;
                }
                s.clear();
                continue;
            }
            int x=a[now];
            if(p>x){
                cout << 0 << endl;
                exit(0);
            }
            s.push_back({x,lx[x],rx[x]+1});
            now=rx[x]+1;
        }
        int sz=s.size();
        if(sz>0){
            vector<vector<ll>> dp(sz + 1, vector<ll>(sz + 1, 0));
            rep(i, sz){
                if(s[i].r-s[i].l>=3){
                    ans = ans*dfs(s[i].l + 1, s[i].r - 1, s[i].x)%MOD9;
                }
                dp[i][i+1]=1;
                dp[i][i] = 1;
            }
            dp[sz][sz] = 1;
            repl(w, 2, sz + 1){
                rep(i, sz - w + 1){
                    int l = i, r = i + w;
                    int mi = IINF;
                    int idx = -1;
                    repl(k, l, r){
                        if(mi > s[k].x){
                            mi = s[k].x;
                            idx = k;
                        }
                    }
                    ll suml = 0, sumr = 0;
                    repl(x, l, idx + 1){
                        suml = (suml + dp[l][x] * dp[x][idx] % MOD9) % MOD9;
                    }
                    repl(x, idx + 1, r + 1){
                        sumr = (sumr + dp[idx + 1][x] * dp[x][r] % MOD9) % MOD9;
                    }
                    dp[l][r] = suml * sumr % MOD9;
                }
            }
            ans = ans * dp[0][sz] % MOD9;
        }
        return ans;
    }
public:
    void solve(){
        cin >> n >> m;
        a=vector<int>(m);
        rep(i,m) cin >> a[i],a[i]--;
        lx=vector<int>(n,-1);
        rx=vector<int>(n,-1);
        rep(i,m){
            if(lx[a[i]]==-1) lx[a[i]]=i;
            rx[a[i]]=i;
        }
        cout << dfs(0,m,-1) << endl;
    }
};

int main(){
    CFS;
    Solver s;
    s.solve();
    return 0;
}