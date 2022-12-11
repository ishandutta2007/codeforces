#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

const int N = 1000;
bool used[N];
int a[N];
string str;

void go(int a, int b)
{
    while (a < b)
    {
        if (!used[a])
            printf("PRINT %c\n", str[a]);
        used[a] = 1;
        printf("RIGHT\n");
        a++;
    }
    while (a > b)
    {
        if (!used[a])
            printf("PRINT %c\n", str[a]);
        used[a] = 1;
        printf("LEFT\n");
        a--;
    }
    if (!used[a])
        printf("PRINT %c\n", str[a]);
    used[a] = 1;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cout << a[n - k];

    return 0;
}