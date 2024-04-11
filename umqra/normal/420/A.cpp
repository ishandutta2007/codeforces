#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e6;
char str[N];
char x[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

bool check(char c)
{
    for (int i = 0; i < 11; i++)
    {
        if (c == x[i])
            return true;
    }
    return false;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] != str[len - i - 1] || !check(str[i]))
        {
            puts("NO");
            return 0;
        }   
    }   
    puts("YES");

    return 0;
}