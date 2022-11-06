#include <bits/stdc++.h>
using namespace std;


#define file "file"
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef complex<double> point;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DEBUG 0
#define dout if(DEBUG) cout

const int MAXN = 1e5 + 5;

int a[MAXN], b[MAXN];
vi timer[MAXN];
bool used[MAXN];
int p[MAXN];

bool cmp(const int &p1, const int &p2){
    return (b[p1] < b[p2]);
}

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
        timer[a[i]].pb(b[i]);
        p[i] = i;
    }
    sort(p, p + n, cmp);
    int cnt = 0;
    for(int i = 1; i <= k; i++){
        if(timer[i].empty()){
            cnt++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int id = p[i];
        if(used[a[id]]){
            if(cnt){
                cnt--;
                ans += b[id];
            }
        }
        else{
            if(timer[a[id]].size() > 1 && cnt){
                cnt--;
                ans += b[id];
                timer[a[id]].pop_back();
            }
            else if(timer[a[id]].size() == 1){
                used[a[id]] = 1;
                timer[a[id]].pop_back();
            }
        }
    }
    cout << ans;
}

int main() {
    #ifdef NASTYA
        assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    #else
    // assert(freopen(file".in", "r", stdin)); assert(freopen(file".out", "w", stdout));
    #endif
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}