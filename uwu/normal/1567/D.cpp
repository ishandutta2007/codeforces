#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int s, n; cin >> s >> n;
        deque<int> nums; int ones = 0;
        for (int i = (int)1e9; i >= 1; i /= 10){
            while (s / i && n){
                if (n == 1) nums.push_back(s);
                else nums.push_back(i);
                s -= i;
                n--;
            }
        }
        while (n){
            while (nums.back() == 1) ones++, nums.pop_back();
            if (nums.back() % 10 == 0){
                int v = nums.back(); nums.pop_back();
                int nxt = v / 10;
                while (v != nxt && n){
                    v -= nxt; nums.push_back(nxt);
                    n--;
                }
                nums.push_back(v);
            }
            else{
                nums.back()--; ones++;
                n--;
            }
        }
        for (int x : nums) cout << x << " ";
        for (int i = 1; i <= ones; ++i) cout << 1 << " ";
        cout << '\n';
    }
}