#include<bits/stdc++.h>
using namespace std;

const int N = 102, INF = 999;
int a[N][N], b[N][N] = {0};

int main(){
    int n, m, y;
    char x;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> x;
            if (x == '.') a[i][j] = 0;
            else if (x == '*'){
                b[i-1][j-1]++;
                b[i-1][j]++;
                b[i-1][j+1]++;
                b[i][j-1]++;
                b[i][j] = INF;
                b[i][j+1]++;
                b[i+1][j-1]++;
                b[i+1][j]++;
                b[i+1][j+1]++;
                a[i][j] = INF;
            }
            else a[i][j] = x - '0';
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] != b[i][j] && (a[i][j] < INF || b[i][j] < INF)){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}