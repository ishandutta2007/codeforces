#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    char c[110][110];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
        {
            if(c[i][j] == '.'){
                if ((i + j) & 1) cout << 'W';
                else cout << 'B';
            }
            else {
                cout << '-';
            }
        }
        cout << endl;
    }
}