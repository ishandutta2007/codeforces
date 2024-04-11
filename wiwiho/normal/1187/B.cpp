#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"}

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

    string s;
    cin >> s;

    vector<vector<int>> pos(26);
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        pos[c - 'a'].pb(i);
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){

        string f;
        cin >> f;

        vector<int> count(26);
        for(int j = 0; j < f.size(); j++){
            count[f[j] - 'a']++;
        }
        int ans = 0;
        for(int j = 0; j < 26; j++){
            if(count[j] == 0){
                continue;
            }
            ans = max(ans, pos[j][count[j] - 1] + 1);
        }

        cout << ans << "\n";

    }

    return 0;
}