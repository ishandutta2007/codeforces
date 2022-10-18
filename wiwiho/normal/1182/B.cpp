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
b << "\n";}

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    StarBurstStream

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }

    int centerx = -1;
    int centery = -1;
    for(int i = 1; i < h - 1; i++){
        for(int j = 1; j < w - 1; j++){
            if(s[i][j] != '*'){
                continue;
            }
            if(s[i][j + 1] != '*'){
                continue;
            }
            if(s[i + 1][j] != '*'){
                continue;
            }
            if(s[i - 1][j] != '*'){
                continue;
            }
            if(s[i][j - 1] != '*'){
                continue;
            }
            if(s[i + 1][j + 1] == '*'){
                continue;
            }
            if(s[i + 1][j - 1] == '*'){
                continue;
            }
            if(s[i - 1][j + 1] == '*'){
                continue;
            }
            if(s[i - 1][j - 1] == '*'){
                continue;
            }
            centerx = j;
            centery = i;
        }
    }
    if(centery == -1){
        cout << "NO\n";
        return 0;
    }

    s[centery][centerx] = '!';
    for(int i = centery + 1; i < h; i++){
        if(s[i][centerx] == '*'){
            s[i][centerx] = '!';
        }
        else{
            break;
        }
    }
    for(int i = centery - 1; i >= 0; i--){
        if(s[i][centerx] == '*'){
            s[i][centerx] = '!';
        }
        else{
            break;
        }
    }
    for(int i = centerx + 1; i < w; i++){
        if(s[centery][i] == '*'){
            s[centery][i] = '!';
        }
        else{
            break;
        }
    }
    for(int i = centerx - 1; i >= 0; i--){
        if(s[centery][i] == '*'){
            s[centery][i] = '!';
        }
        else{
            break;
        }
    }

    bool ans = true;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '*'){
                ans = false;
                break;
            }
        }
    }
    cout << (ans ? "YES" : "NO") << "\n";

    return 0;
}