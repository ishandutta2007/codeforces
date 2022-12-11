#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int a[N][2];
int ans[N];


int main() {
    int n;
    cin >> n;
    for(int j = 0; j <= 1; j++)
    for(int i = 1; i <= n; i++){
        cin >> a[i][j];
    }
    memset(ans, -1, sizeof(ans));
    for(int turn = n; turn >= 1; turn--){
        for(int i = 1; i <= n; i++) if (ans[i] == -1 && a[i][0] == 0 && a[i][1] == 0){
            ans[i] = turn;
        }
        for(int i = 1; i <= n; i++) if (ans[i] == turn){
            for(int j = 1; j < i; j++) a[j][1]--;
            for(int j = i + 1; j <= n; j++) a[j][0]--;
        }
        for(int i = 1; i <= n; i++) if (ans[i] == -1){
            
            if (a[i][0] < 0 || a[i][1] < 0){
                cout <<"NO";
                return 0;
            }
        }
    }
    if (count(ans + 1, ans + n + 1, -1)){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}