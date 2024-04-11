#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

vector<ll> init() {
    vector<ll> ret; vector<int> a(18);
    for(int i=0;i<18;++i) {
        for(int j=i+1;j<18;++j) {
            for(int k=j+1;k<18;++k) {
                for(int x=1;x<=9;++x) {
                    for(int y=1;y<=9;++y) {
                        for(int z=1;z<=9;++z) {
                            a[i]=x,a[j]=y,a[k]=z;
                            ll tmp=0;
                            for(int p=0;p<18;++p) tmp=tmp*10+a[p];
                            ret.push_back(tmp);
                            a[i]=a[j]=a[k]=0;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<18;++i) {
        for(int j=i+1;j<18;++j) {
            for(int x=1;x<=9;++x) {
                for(int y=1;y<=9;++y) {
                    a[i]=x,a[j]=y;
                    ll tmp=0;
                    for(int p=0;p<18;++p) tmp=tmp*10+a[p];
                    ret.push_back(tmp);
                    a[i]=a[j]=0;
                }
            }
        }
    }
    for(int i=0;i<18;++i) {
        for(int x=1;x<=9;++x) {
            a[i]=x;
            ll tmp=0;
            for(int p=0;p<18;++p) tmp=tmp*10+a[p];
            ret.push_back(tmp);
            a[i]=0;
        }
    }
    sort(ret.begin(), ret.end());
    ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
    ret.push_back(1e18);
    return ret;
}
int main() {
    vector<ll> a = init();
    auto solve = [&](ll x) -> ll {
        return upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
    };
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << endl;
    }
}
// 1 1000000000000000000