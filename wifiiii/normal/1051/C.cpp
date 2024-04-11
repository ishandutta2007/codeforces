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

int main() {
    int n;
    cin >> n;
    unordered_map<int,int> mp;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i], mp[a[i]]++;
    int cnt1 = 0;
    for(auto p : mp) if(p.second == 1) ++cnt1;
    if(cnt1 % 2 == 0) {
        cout << "YES" << endl;
        int mid = cnt1 / 2;
        for(int i=0;i<n;++i) {
            if(mp[a[i]] == 1) {
                if(mid) cout << 'A', --mid;
                else cout << 'B';
            } else {
                cout << 'A';
            }
        }
        cout << endl;
    } else {
        int ok = 0, tmp = 0;
        for(auto p : mp) {
            if(p.second >= 3) {
                tmp = p.first;
                ok = 1;
                break;
            }
        }
        if(ok) {
            cout << "YES" << endl;
            int mid = cnt1 / 2 + 1;
            for(int i=0;i<n;++i) {
                if(a[i] == tmp) {
                    cout << 'B';
                    tmp = -1;
                } else if(mp[a[i]] == 1) {
                    if(mid) cout << 'A', --mid;
                    else cout << 'B';
                } else {
                    cout << 'A';
                }
            }
        } else {
            cout << "NO" << endl;
        }
    }
}