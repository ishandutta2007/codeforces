#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define pii pair <int, int>
#define LL long long
using namespace std;

pii a[100005];

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf ("%d%d", &x, &y);
        a[i] = pii(x, y);
    }
    sort (a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++){
        int x = a[i - 1].first, y = a[i - 1].second, x2 = a[i].first, y2 = a[i].second;
        if (x2 > x && y2 < y){
            cout << "Happy Alex\n";
            return 0;
        }
    }
    cout << "Poor Alex\n";
}