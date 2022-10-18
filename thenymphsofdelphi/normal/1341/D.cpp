#include<bits/stdc++.h>
using namespace std;

string dig[10] = {"1110111",
                  "0010010",
                  "1011101",
                  "1011011",
                  "0111010",
                  "1101011",
                  "1101111",
                  "1010010",
                  "1111111",
                  "1111011"};

const int N = 2e3 + 5;

int n, k;
string s[N];
bool dp[N][N];

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; i--){
        for (int j = 0; j <= k; j++){
            for (auto t: dig){
                bool ck = 0; int dif = 0;
                for (int idx = 0; idx < 7; idx++){
                    if (t[idx] == '0' && s[i][idx] == '1'){
                        ck = 1; break;
                    }
                    if (t[idx] != s[i][idx]) dif++;
                }
                if (ck) continue;
                if (j >= dif && dp[i + 1][j - dif]){
                    dp[i][j] = 1;
                    break;
                }
            }
        }
    }
    if (!dp[1][k]){
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 9; j >= 0; j--){
            bool ck = 0; int dif = 0;
            for (int idx = 0; idx < 7; idx++){
                if (dig[j][idx] == '0' && s[i][idx] == '1'){
                    ck = 1; break;
                }
                if (dig[j][idx] != s[i][idx]) dif++;
            }
            if (ck) continue;
            if (k >= dif && dp[i + 1][k - dif]){
                cout << j;
                k -= dif;
                break;
            }
        }
    }
}