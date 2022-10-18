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

bool check(int n, string& s, int d){
    queue<int> q;
    q.push(0);
    set<int> st;
    for(int i = 1; i <= n + 1; i++) st.insert(i);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == n + 1) break;
//        cerr << now << "  ";
//        printv(st, cerr);
        if(s[now] == 'L'){
            while(st.lower_bound(now - d) != st.end() && *st.lower_bound(now - d) < now){
//                cerr << now << " " << *st.lower_bound(now - d) << "\n";
                q.push(*st.lower_bound(now - d));
                st.erase(st.lower_bound(now - d));
            }
        }
        else{
            while(st.lower_bound(now) != st.end() && *st.lower_bound(now) <= now + d){
//                cerr << now << " " << *st.lower_bound(now) << "\n";
                q.push(*st.lower_bound(now));
                st.erase(st.lower_bound(now));
            }
        }
    }
//    cerr << d << "   ";
//    printv(st, cerr);

    return st.find(n + 1) == st.end();
}

int main(){
    StarBurstStream
    cerr.tie(0);

    int T;
    cin >> T;

    while(T--){

        string s;
        cin >> s;
        s = 'R' + s;

        int l = 1, r = s.size();
        while(l < r){
            int m = (l + r) / 2;
            if(check(s.size(), s, m)) r = m;
            else l = m + 1;
        }

        cout << l << "\n";
    }

    return 0;
}