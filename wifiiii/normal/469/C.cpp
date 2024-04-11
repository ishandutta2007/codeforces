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
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;

int main() {
    int n;
    cin >> n;
    if(n <= 3) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    if(n == 4) {
        cout << "3 * 2 = 6\n";
        cout << "6 * 4 = 24\n";
        cout << "1 * 24 = 24\n";
    }
    else if(n == 5) {
        cout << "3 + 5 = 8\n";
        cout << "2 - 1 = 1\n";
        cout << "4 - 1 = 3\n";
        cout << "3 * 8 = 24\n";
    }
    else if(n == 6) {
        cout << "5 - 3 = 2\n";
        cout << "2 - 2 = 0\n";
        cout << "0 + 1 = 1\n";
        cout << "4 * 6 = 24\n";
        cout << "24 * 1 = 24\n";
    } else {
        if(n & 1) {
            int cnt = n - 1;
            cout << "3 + 5 = 8\n";
            cout << "2 - 1 = 1\n";
            cout << "4 - 1 = 3\n";
            cout << "3 * 8 = 24\n";
            cnt -= 4;
            for(int i=6;i<=n;i+=2) {
                cout << i+1 << " - " << i << " = 1\n";
                --cnt;
            }
            while(cnt--) cout << "1 * 24 = 24\n";
        } else {
            int cnt = n - 1;
            cout << "5 - 3 = 2\n";
            cout << "2 - 2 = 0\n";
            cout << "0 + 1 = 1\n";
            cout << "4 * 6 = 24\n";
            cout << "24 * 1 = 24\n";
            cnt -= 5;
            for(int i=7;i<=n;i+=2) {
                cout << i+1 << " - " << i << " = 1\n";
                --cnt;
            }
            while(cnt--) cout << "1 * 24 = 24\n";
        }
    }
}