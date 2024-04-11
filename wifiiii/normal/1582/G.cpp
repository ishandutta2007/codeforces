#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;
int np[maxn], mp[maxn];
vector<pair<int,int>> stk[maxn];
multiset<int> ms;
int main() {
    np[1] = 1;
    for(int i = 2; i < maxn; ++i) {
        if(np[i]) continue;
        mp[i] = i;
        if(1ll * i * i < maxn) {
            for(int j = i * i; j < maxn; j += i) {
                if(!np[j]) np[j] = 1, mp[j] = i;
            }
        }
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    string s;
    cin >> s;
    ll ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        if(s[i] == '*') {
            int x = a[i];
            while(x != 1) {
                int p = mp[x], cnt = 0;
                while(x % p == 0) {
                    cnt++;
                    x /= p;
                }
                while(!stk[p].empty()) {
                    if(stk[p].back().first > cnt) {
                        stk[p].back().first -= cnt;
                        break;
                    } else {
                        ms.erase(ms.find(stk[p].back().second));
                        cnt -= stk[p].back().first;
                        stk[p].pop_back();
                    }
                }
            }
        } else {
            int x = a[i];
            while(x != 1) {
                int p = mp[x], cnt = 0;
                while(x % p == 0) {
                    cnt++;
                    x /= p;
                }
                stk[p].push_back({cnt, i});
                ms.insert(i);
            }
        }
        int r = n;
        if(!ms.empty()) r = *ms.begin();
        ans += r - i;
    }
    cout << ans << '\n';
}