//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;
#define forn(i,n) for (int i = 0; i < int(n); ++i)

typedef vector<int> vi;
void manacher(const string &s, vi &odd, vi &even) {
    int n = s.size();
    odd.resize(n);
    int c = -1, r = -1;
    forn (i, n) {
        int k = (r <= i ? 0 : min(odd[2 * c - i], r - i));
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k])
            ++k;
        odd[i] = k;
        if (i + k > r)
            r = i + k, c = i;
    }
    c = -1, r = -1;
    even.resize(n - 1);
    forn (i, n - 1) {
        int k = (r <= i ? 0 : min(even[2 * c - i], r - i));
        while (i + k + 1 < n && i - k >= 0 &&
                s[i + k + 1] == s[i - k])
            ++k;
        even[i] = k;
        if (i + k > r)
            c = i, r = i + k;
    }
}

void manacher_shit(const string & s, vector<int> & odd, vector<int> & even){
    int n = s.length();
    odd.resize(n);
    F(i, 0, n){
        int len = 1;
        while(i - len >= 0 && i + len < n && s[i - len] == s[i + len])++len;
        odd[i] = len;
    }
    even.resize(n - 1);
    F(i, 0, n - 1){
        int len = 0;
        while(i - len >= 0 && i + len + 1 < n && s[i - len] == s[i + len + 1])++len;
        even[i] = len;
    }
}

string solve(string s){
    int n = s.length();
    int base = 0;
    while(2 * base < n && s[base] == s[n - 1 - base])++base;
    if(2 * base >= n)return s;
    base--;
    vector<int> odd, even;
    manacher(s, odd, even);
    int L = base, R = n - 1 - base;
    int best = 2 * (base + 1);
    F(mid, 0, n){
        int d = odd[mid] - 1;
        /*int real_d = min(min(d, mid - base - 1), n - 1 - base - mid - 1);
        if(real_d >= 0){
            int len = 2 * (1 + base) + 2 * real_d + 1;
            if(len > best){
                best = len;
                if(mid - base - 1 == real_d)L = mid + real_d; else L = base;
                if(mid + real_d + 1 == n - base - 1)R = mid - real_d; else R = n - base - 1;
            }
        }*/
        if(mid - d - 1 <= base){
            int new_l = mid + d, new_r = n - min(base, mid - d - 1) - 1;
            if(new_r > mid + d && new_l + 1 + (n - new_r) > best){
                best = new_l + 1 + n - new_r;
                L = new_l; R = new_r;
            }
        }
        if(mid + d + 1 >= n - 1 - base){
            int new_l = min(base, n - 1 - (mid + d + 1)), new_r = mid - d;
            if(new_l < mid - d && new_l + 1 + (n - new_r) > best){
                best = new_l + 1 + n - new_r;
                L = new_l; R = new_r;
            }
        }
    }
    F(mid, 0, n - 1){
        /*int d = even[mid];
        int real_d = min(min(d, mid - base), n - 1 - base - mid - 1);
        if(real_d >= 0){
            int len = 2 * (1 + base) + 2 * real_d;
            if(len > best){
                best = len;
                if(mid - base == real_d)L = mid + real_d; else L = base;
                if(mid + real_d + 1 == n - base - 1)R = mid - real_d + 1; else R = n - base - 1;
            }
        }*/

        int d = even[mid];
        if(!d)cont;
        if(mid - d <= base){
            int new_l = mid + d, new_r = n - min(base, mid - d) - 1;
            if(new_r > mid + d && new_l + 1 + (n - new_r) > best){
                best = new_l + 1 + n - new_r;
                L = new_l; R = new_r;
            }
        }
        if(mid + d + 1 >= n - 1 - base){
            int new_l = min(base, n - 1 - (mid + d + 1)), new_r = mid - d + 1;
            if(new_l < mid - d + 1 && new_l + 1 + (n - new_r) > best){
                best = new_l + 1 + n - new_r;
                L = new_l; R = new_r;
            }
        }
    }
    if(best == n)ret s;
    else ret s.substr(0, L + 1) + (R < n ? s.substr(R) : "");
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
    return 0;
}