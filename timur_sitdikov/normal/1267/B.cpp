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

const int MAXN = 3e5 + 5;

char s[MAXN];
char let[MAXN];
int cnt[MAXN];
int top;

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    let[top] = s[0];
    cnt[top] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i - 1]){
            let[++top] = s[i];
            cnt[top] = 1;
        }
        else cnt[top]++;
    }
    top++;
    int good = 1;
    if(top & 1){
        for(int i = 0; i < top; i++){
            if(let[i] != let[top - 1 - i]){
                good = 0;
            }
            else{
                if(i == top - 1 - i){
                    if(cnt[i] + 1 < 3) good = 0;
                }
                else if(cnt[i] + cnt[top - 1 - i] < 3) good = 0;
            }
        }
    }
    else good = 0;
    if(good){
       cout << cnt[top / 2] + 1;
    }
    else cout << 0;
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