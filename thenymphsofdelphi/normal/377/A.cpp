#include<bits/stdc++.h>
using namespace std;

const int N = 505;

int a[N][N], ck[N][N];
int n, m, k, r = 0;
int xs = -1, ys = -1, cnt = 0;

void print(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] == 0){
                cout << '#';
            }
            else if (a[i][j] == 1){
                cout << '.';
            }
            else{
                cout << 'X';
            }
        }
        cout << endl;
    }
}

void ff(int x, int y){
    if (cnt >= r - k){
        return;
    }
    if (a[x][y] <= 1){
        return;
    }
    if (x == 0 || y == 0 || x > n || y > m){
        return;
    }
    a[x][y] = 1;
    cnt++;
    ff(x - 1, y);
    ff(x + 1, y);
    ff(x, y - 1);
    ff(x, y + 1);
    return;
}

int main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++){
            if (s[j - 1] == '#'){
                a[i][j] = 0;
            }
            else{
                a[i][j] = 2;
                r++;
                xs = i;
                ys = j;
            }
        }
    }
    if (r == 0){
        print();
        return 0;
    }
    ff(xs, ys);
    print();
}