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
}}\
b << "\n"

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int countS = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    set<string> ss;
    queue<string> q;
    q.push(s);
    ss.insert(s);
    int ans = 0;
    while(!q.empty() && ss.size() < k){
        string t = q.front();
        q.pop();
        for(int i = 0; i < t.size(); i++){
            string ne = t;
            ne.erase(i, 1);
            if(ss.count(ne)){
                continue;
            }
            if(ss.size() + 1 > k){
                break;
            }
            q.push(ne);
            ss.insert(ne);
            ans += s.size() - ne.size();
        }
    }

    if(ss.size() < k){
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }

    return 0;
}