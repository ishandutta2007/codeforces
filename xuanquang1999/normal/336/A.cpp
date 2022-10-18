#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define mp make_pair
#define pb push_back

int x, y;

int main() {
    scanf("%d%d", &x, &y);
    if (x > 0 && y > 0) printf("%d %d %d %d", 0, x+y, x+y, 0);
    else if (x < 0 && y < 0) printf("%d %d %d %d", x+y, 0, 0, x+y);
    else if (x < 0 && y > 0) printf("%d %d %d %d", x-y, 0, 0, y-x);
    else if (x > 0 && y < 0) printf("%d %d %d %d", 0, y-x, x-y, 0);
}