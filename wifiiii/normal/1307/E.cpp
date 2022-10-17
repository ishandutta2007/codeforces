#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int mod = 1e9+7;
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin>>a[i];
        --a[i];
    }
    vector<vector<int>> cows(n);
    vector<int> types;
    for(int i=0;i<m;++i) {
        int f,h;
        cin>>f>>h;
        --f;
        cows[f].push_back(h);
        types.push_back(f);
    }
    sort(all(types));
    types.erase(unique(all(types)), types.end());
    for(int i : types) sort(all(cows[i]));
    int mx = 0;
    vector<int> left(n), right(n);
    for(int i=0;i<n;++i) right[a[i]]++;
    ll ans = -1, ans2 = 0;
    {
        ll tmp = 0, ways = 1;
        for(int j : types) {
            int cnt2 = upper_bound(all(cows[j]), right[j]) - cows[j].begin();
            if(cnt2) {
                tmp += 1;
                ways = ways * cnt2 % mod;
            }
        }
        if(tmp > ans) {
            ans = tmp;
            ans2 = ways;
        } else if(tmp == ans) {
            ans2 = (ans2 + ways) % mod;
        }
    }

    for(int i=0;i<n;++i) {
        // (0, i], (i, n)
        left[a[i]]++; right[a[i]]--;
        int ok = 0, tmp = 0;
        ll ways = 1;
        for(int j : types) {
            if(j == a[i]) {
                int num = upper_bound(all(cows[j]), left[j]) - lower_bound(all(cows[j]), left[j]);
                int cnt2 = upper_bound(all(cows[j]), right[j]) - cows[j].begin();
                if(num) {
                    ok = 1;
                    int res = cnt2;
                    if(right[j] >= left[j]) res--;
                    if(!res) {
                        tmp += 1;
                        ways = ways * num % mod;
                    } else {
                        tmp += 2;
                        if(right[j] >= left[j]) ways = ways * (cnt2 * num - num) % mod;
                        else ways = ways * num * cnt2 % mod;
                    }
                }
                if(!ok) break;
                continue;
            }
            int cnt1 = upper_bound(all(cows[j]), left[j]) - cows[j].begin();
            int cnt2 = upper_bound(all(cows[j]), right[j]) - cows[j].begin();
            if(cnt1 > cnt2) swap(cnt1, cnt2);
            if(!cnt1 && !cnt2) {
                continue;
            } else if(cnt2 && cnt1 && cnt2 > 1) {
                tmp += 2;
                ways = ways * (cnt1 * cnt2 - cnt1) % mod;
            } else {
                tmp += 1;
                ways = ways * (cnt1 + cnt2) % mod;
            }
        }
        if(!ok) continue;
        if(tmp > ans) {
            ans = tmp;
            ans2 = ways;
        } else if(tmp == ans) {
            ans2 = (ans2 + ways) % mod;
        }
    }
    cout << ans << " " << ans2 << endl;
}