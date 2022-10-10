#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define optimize_io ios::sync_with_stdio(false); cin.tie(0)
#define ri(x) int x; cin >> x
#define rc(x) char x; cin >> x
#define r32(x) int32_t x; cin >> x
#define rll(x) long long x; cin >> x
#define rd(x) double x; cin >> x;
#define rld(x) long double x; cin >> x;

template<typename T> inline void read(T & x){ cin >> x; }
template<typename T, typename ... Types>
inline void read(T & x, Types & ...args){ cin >> x; }

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
typedef long double LD;

string build(int a, int b, char mr1, char mr2, int reps = 16) {
    string s;
   for(int i = 0; i < a; i++) s += 'a'+i;

   for(int i = 0; i < reps; i++){
       if(i&1) {
           string suf = s.substr((int)s.size()-a);
           set<char> st(all(suf));

           int ptr = 0;
           for(int j = 0; j < a; j++) {
               while(st.count('a'+ptr)) ptr++;
               st.insert('a'+ptr);
               s += 'a'+ptr;
           }
       } else {
           for(int j = 0; j < b; j++)
               s += i%4 == 0 ? mr1 : mr2;
       }
   }

   return s;
}

int dumb(int a, int b, int L, int R, char mr1, char mr2) {
    string s = build(a, b, mr1, mr2, 100);
    assert(s.size() > R);

    set<char> st;
    for(int i = L; i <= R; i++) {
        st.insert(s[i]);
    }

    return st.size();
}

int solve(int a, int b, int L, int R, char mr1, char mr2){
   string s = build(a, b, mr1, mr2);

   int sz = (int)s.size()-a;
   set<char> st;
   for(int i = 0; i < a; i++) if(i >= L && i <= R)
       st.insert(s[i]);
   
   string ss = s.substr(a);
   L = max(L, a);
   
   if(R-L+1 > 4LL*ss.size()) {
       for(char c : ss) st.insert(c);
   } else {
       for(int i = L; i <= R; i++) {
           st.insert(ss[(i-a)%sz]);
       }
   }

   return st.size();
}

int32_t main() {
    int a, b, L, R;
    cin >> a >> b >> L >> R;
    L--, R--;

    int ans = 1e18;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            //int f1 = solve(a, b, L, R, 'a'+i, 'a'+j);
            //int f2 = dumb(a, b, L, R, 'a'+i, 'a'+j);
            //if(f1 != f2) {
                //cout << "EPA " << (char)('a'+i) << endl;
                //cout << f1 << " " << f2 << endl;
                //return 0;
            //}

            ans = min(ans, solve(a, b, L, R, 'a'+i, 'a'+j));
        }
    }

    cout << ans << endl;
}