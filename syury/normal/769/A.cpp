#include <bits/stdc++.h>

#define f(_i, _n) for (auto _i = 0; _i < _n; _i++)
#define F(_i, _k, _n) for (auto _i = _k; _i < _n; _i++)
#define fr(_i, _k, _n) for (auto _i = _k; _i < _n; _i++)
#define r(_t, _n)     _t _n;     cin >> _n;
#define ra(_type, _name, _len)_type _name[_len]; f(_i, _len)    cin >> _name[_len];
#define mp make_pair
#define re return
#define takedown re 0;
#define fi first
#define se second
#define in(_name) freopen(_name, "r", stdin);
#define out(_name) freopen(_name, "w", stdout);
#define pb push_back
#define fill(_a, _n) memset(_a, _n, sizeof(_a))
#define all(_v) _v.begin(), _v.end()

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int a[5];
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    f(i, n) cin >> a[i];
    sort(a, a+n);
    cout << a[n/2];
}