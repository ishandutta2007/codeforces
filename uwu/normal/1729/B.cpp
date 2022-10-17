#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        string s; cin >> s;
        string ans;
        for (int i = 0; i < N; ++i){
            if (i + 2 > N-1 || s[i+2] != '0' || (i+3 < N && s[i+2] == '0' && s[i+3] == '0')){
                ans += (s[i] - '0') + 'a' - 1;
            }
            else{
                int num = (s[i] - '0')*10 + (s[i+1] - '0');
                ans += (char)(num + 'a' - 1);
                i+=2;
            }
        }
        cout << ans << '\n';
    }
}