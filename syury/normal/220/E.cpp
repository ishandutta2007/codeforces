#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
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

const int N = (int)1e5 + 55;

template<int N>
struct F{
    int t[N];
    
    int get(int pref){
        int res = 0;
        while(pref){
            res += t[pref];
            pref -= pref&-pref;
        }
        return res;
    }

    void inc(int i){
        while(i < N){
            ++t[i];
            i += i&-i;
        }
    }

    void dec(int i){
        while(i < N){
            --t[i];
            i += i&-i;
        }
    }
};

int a[N];
int to_right[N];
ll s_right[N];
int all_vals[N];
int n;
ll k;
F<N> le, ri, mid;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%lld", &n, &k);
    F(i, 0, n)
        scanf("%d", a + i);
    memcpy(all_vals, a, n * sizeof(int));
    sort(all_vals, all_vals + n);
    int all_sz = unique(all_vals, all_vals + n) - all_vals;
    DF(i, n - 1, 0){
        a[i] = lower_bound(all_vals, all_vals + all_sz, a[i]) - all_vals;
        s_right[i] = to_right[i] = ri.get(a[i]);
        if(i + 1 != n)s_right[i] += s_right[i + 1];
        ri.inc(a[i] + 1);
    }
    if(s_right[0] <= k){
        cout << n * 1ll * (n - 1)/2 << endl;
        return 0;
    }
    ll ans = 0;
    int ptr = -1;
    ll inversions = s_right[0];
    F(i, 0, n){
        if(i - 1 != -1 && i - 1 <= ptr){
            mid.dec(a[i - 1] + 1);
            inversions += i - 1 - le.get(a[i - 1] + 1);
            inversions += to_right[i - 1] - mid.get(a[i - 1]);
        }
        if(ptr < i - 1)ptr = i - 1;
        if(i - 1 >= 0)
            le.inc(a[i - 1] + 1);
        while(ptr + 1 < n){
            ll delta = to_right[ptr + 1] + i - le.get(a[ptr + 1] + 1);
            if(inversions - delta > k){
                inversions -= delta;
                ++ptr;
                mid.inc(a[ptr] + 1);
            }
            else break;
        }
        if(i){
            ans += n - (ptr + 1);
            if(n != ptr + 1)--ans;
        }
    }
    cout << ans << endl;
    return 0;
}