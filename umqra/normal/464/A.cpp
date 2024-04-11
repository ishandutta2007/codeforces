#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)2e3;
char str[N];
char tStr[N];

void printAns(int len)
{
    for (int i = 0; i < len; i++)
        printf("%c", tStr[i]);
}

bool checkSumbol(char c, int pos)
{
    if (pos > 0 && tStr[pos - 1] == c)
        return false;
    if (pos > 1 && tStr[pos - 2] == c)
        return false;
    return true;
}

bool checkString(int st, int len, int p)
{
    for (int i = 0; i <= st; i++)
        tStr[i] = str[i];
    for (int i = st + 1; i < len; i++)
        tStr[i] = '?';
    
    for (int i = 0; i < len; i++)
    {
        char c;
        for (c = 'a'; c < 'a' + p; c++)
        {
            if (!checkSumbol(c, i))
                continue;
            break;
        }
        if (c - 'a' >= p)
            return false;
        if (tStr[i] == '?')
            tStr[i] = c;
        if (!checkSumbol(tStr[i], i))
            return false;
    }
    return true;
}

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    scanf(" %s", str);

    for (int i = n - 1; i >= 0; i--)
    {
        int t = str[i] - 'a';
        for (int newLetter = t + 1; newLetter < p; newLetter++)
        {
            str[i] = newLetter + 'a';
            if (checkString(i, n, p))
            {
                printAns(n);
                return 0;
            }
        }
    }
    puts("NO");

    return 0;
}