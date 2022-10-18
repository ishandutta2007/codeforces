#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    for(int testcase = 0; testcase < n; testcase++){
        vector<pair<char, int>> worda;
        vector<pair<char, int>> wordb;
        string a, b;
        cin >> a >> b;

        for(int i = 0; i < a.size(); i++){
            if(i != 0 && a[i] == a[i-1]){
                worda.back().second++;
            }
            else{
                worda.pb(mp(a[i], 1));
            }
        }

        for(int i = 0; i < b.size(); i++){
            if(i != 0 && b[i] == b[i - 1]){
                wordb.back().second++;
            }
            else{
                wordb.pb(mp(b[i], 1));
            }
        }

        if(worda.size() != wordb.size()){
            cout << "NO\n";
            continue;
        }
        
        bool ans = true;

        for(int i = 0; i < worda.size(); i++){
            if(worda[i].first != wordb[i].first || worda[i].second > wordb[i].second){
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }


    return 0;
}