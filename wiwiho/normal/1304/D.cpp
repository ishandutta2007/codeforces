//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
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
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> b(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++){
            if(s[i - 1] == '<'){
                if(i == n - 1 || s[i] != '>') b[i] = ++r;
            }
            else{
                int j;
                for(j = i; j < n && s[j - 1] == '>'; j++);
                j--;
                int tmp = j;
                for(; j >= i - 1; j--) b[j] = ++r;
                i = tmp;
            }
        }
        //cerr << l << " " << r << "\n";

        int t = n - r;
        for(int i = 0; i < n; i++) b[i] += t;

        vector<int> a(n);
        a[0] = n;
        l = n;
        for(int i = 1; i < n; i++){
            if(s[i - 1] == '>'){
                if(i == n - 1 || s[i] != '<') a[i] = --l;
            }
            else{
                int j;
                for(j = i; j < n && s[j - 1] == '<'; j++);
                j--;
                int tmp = j;
                for(; j >= i - 1; j--) a[j] = --l;
                i = tmp;
            }
        }
        //printv(a, cerr);
        t = 1 - l;
        for(int i = 0; i < n; i++) a[i] += t;

        //printv(a, cerr);

        printv(a, cout);
        printv(b, cout);

    }

    return 0;
}