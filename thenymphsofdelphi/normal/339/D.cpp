#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define For(i, a, b) for (int i = a; i < b; i++)
#define ForE(i, a, b) for (int i = a; i <= b; i++)
#define Forl(i, a, b) for (int i = a; i > b; i--)
#define ForlE(i, a, b) for (int i = a; i >= b; i--)

const int N = 150005;

int n, m;
int a[18][N]/*, b[18]*/;

void print(){
    ForlE(i, n, 0){
        For(j, 0, (1 << i)){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    For(i, 0, (1 << n)){
        cin >> a[n][i];
    }
    ForlE(i, n - 1, 0){
        For(j, 0, (1 << i)){
            if ((n - i) & 1){
                a[i][j] = (a[i + 1][j * 2] | a[i + 1][j * 2 + 1]);
            }
            else{
                a[i][j] = (a[i + 1][j * 2] ^ a[i + 1][j * 2 + 1]);
            }
        }
    }
    //print();
    while (m--){
        int x, y, x2, t;
        cin >> x >> y;
        x--;
        //x2 = x;
        //t = a[n][x];
        a[n][x] = y;
        ForlE(i, n - 1, 0){
            x /= 2;
            //b[i] = a[i][x];
            if ((n - i) & 1){
                a[i][x] = (a[i + 1][x * 2] | a[i + 1][x * 2 + 1]);
            }
            else{
                a[i][x] = (a[i + 1][x * 2] ^ a[i + 1][x * 2 + 1]);
            }
        }
        cout << a[0][0] << endl;
        /*
        x = x2;
        ForlE(i, n - 1, 0){
            x /= 2;
            a[i][x] = b[i];
        }
        a[n][x2] = t;
        */
    }
}