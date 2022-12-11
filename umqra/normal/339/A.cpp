#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5;
char sum[N];
char n[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
                                                   
    string str;
    cin >> str;
    int t = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] != '+')
            n[t++] = str[i];
    }
    sort(n, n + t);
    for (int i = 0; i < t; i++)
    {
        printf("%c", n[i]);
        if (i != t - 1)
            putchar('+');
    }

    return 0;
}