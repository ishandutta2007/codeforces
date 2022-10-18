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

    int q;
    cin >> q;

    while(q--){

        string s, t, p;
        cin >> s >> t >> p;

        if(s.size() > t.size()){
            cout << "NO\n";
            continue;
        }

        map<char, int> cnt;
        for(int i = 0; i < p.size(); i++){
            cnt[p[i]]++;
        }

        bool ans = true;
        int j = 0;
        for(int i = 0; i < t.size(); i++){
            if(j < s.size() && s[j] == t[i]){
                j++;
                continue;
            }
            if(cnt[t[i]]){
                cnt[t[i]]--;
            }
            else{
                ans = false;
                break;
            }
        }
        if(j < s.size()){
            ans = false;
        }

        cout << (ans ? "YES\n" : "NO\n");

    }

    return 0;
}