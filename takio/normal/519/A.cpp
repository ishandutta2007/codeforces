#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100100;

int v[1010];

int main () {
//    freopen ("in.txt", "r", stdin);
    char c;
    v['q'] = 9; v['r'] = 5; v['b'] = 3; v['n'] = 3; v['p'] = 1; v['k'] = 0;
    v['Q'] = -9; v['R'] = -5; v['B'] = -3; v['N'] = -3; v['P'] = -1; v['K'] = 0;
    int sum = 0;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> c;
            sum += v[c];
        }
    }
    if (sum == 0) cout << "Draw";
    else if (sum > 0) cout << "Black";
    else cout << "White";
}