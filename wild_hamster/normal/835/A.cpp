#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
using namespace std;
int n,i,j,k, a[505][505], down[505][505], up[505][505],x,y;
char c[505][505];
int main() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if (n*x1 + 2*x2 < n*y1 + 2*y2)
        cout << "First" << endl;
    else
    if (n*x1 + 2*x2 > n*y1 + 2*y2)
        cout << "Second" << endl;
    else
        cout << "Friendship" << endl;
    return 0;
}