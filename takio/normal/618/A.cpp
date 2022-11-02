#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;
int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;

    for (int i = 30; i >= 0; i--) if (n & (1 << i)) cout << i + 1 <<' ' ;
}