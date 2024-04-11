#include <bits/stdc++.h>
 
#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define fr front()
#define po pop()
#define ba back()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
 
//#define TEST
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){
 
    StarBurstStream
 
    int n;
    cin >> n;

    int count = 0;
    map<int, int> m;
    vector<int> a(n);

    string f = "sjfnb";
    string s = "cslnb";

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a[i] = t;
        m[t]++;
        if(m[t] > 2){
            return cout << s << "\n", 0;
        }
        if(m[t] == 2){
            count++;
            if(count > 1){
                return cout << s << "\n", 0;
            }
            if(t == 0){
                return cout << s << "\n", 0;
            }
        }
    }

    int now = 0;
    bool inc = true;
    for(pair<int, int> p : m){
        if(p.F != now){
            inc = false;
        }
        if(p.S == 2 && m[p.F - 1] != 0){
            return cout << s << "\n", 0;
        }
        now++;
    }
    if(inc){
        return cout << s << "\n", 0;
    }

    lsort(a);
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += (a[i] - i) % 2;
    }
    if(sum % 2 == 1){
        return cout << f << "\n", 0;
    }
    else{
        return cout << s << "\n", 0;
    }
 
    return 0;
}