#include <iostream>
#include <cstdio>
#include <algorithm>    
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define X first
#define Y second
#define mp make_pair

const int N = (int)1e6;
char str[N], st[N];
int r;

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
          
    scanf("%s", str);
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        if (r > 0 && st[r - 1] == str[i])
            r--;
        else
            st[r++] = str[i];
    }
    if (r == 0)
        puts("Yes");
    else
        puts("No");

    return 0;
}