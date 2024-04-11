#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;

const int N = 1e2 + 10;
int n, k;
char c[N][N];
int cnt[N][N];
int x = 1, y = 1;

int main(){
    string s;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> s;
        for (int j = 1; j <= n; j++){
            c[i][j] = s[j - 1];
        }
    }
    for (int i = 1; i <= n; i++){
        int last = 0;
        for (int j = 1; j <= n; j++){
            if (c[i][j] == '#'){
                last = j;
            }
            else{
                if (j - last >= k){
                    for (int L = j - k + 1; L <= j; L++){
                        cnt[i][L]++;
                    }
                }
            }
        }
    }
    for (int j = 1; j <= n; j++){
        int last = 0;
        for (int i = 1; i <= n; i++){
            if (c[i][j] == '#'){
                last = i;
            }
            else{
                if (i - last >= k){
                    for (int L = i - k + 1; L <= i; L++){
                        cnt[L][j]++;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (cnt[i][j] > cnt[x][y]){
                x = i;
                y = j;
            }
        }
    }
    cout << x << " " << y;
}