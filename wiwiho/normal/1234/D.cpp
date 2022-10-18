//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cerr.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 10007;
const ll MAX = 1LL << 60;

int main(){
    StarBurstStream

    string s;
    cin >> s;

    vector<set<int>> v(26);
    for(int i = 0; i < s.size(); i++){
        v[s[i] - 'a'].insert(i);
    }
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int pos; char c;
            cin >> pos >> c;
            pos--;
            v[s[pos] - 'a'].erase(pos);
            s[pos] = c;
            v[c - 'a'].insert(pos);
            continue;
        }
        int cnt = 0;
        int l, r;
        cin >> l >> r;
        l--; r--;
        for(int i = 0; i < 26; i++){
            //cerr << (char)('a' + i) << "  ";
            //printv(v[i], cerr);
            auto lower = v[i].lower_bound(l);
            auto upper = v[i].upper_bound(r);
            if(lower != upper){
                cnt++;
                //cerr << "test\n";
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}