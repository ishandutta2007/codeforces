#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n, m;
    scanf("%d%d", &n, &m);
    int s, f;
    scanf("%d%d", &s, &f);
    int curT = 1;
    for (int i = 0; i < m; i++)
    {              
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        while (curT < t && s != f)
        {
            if (s > f)
            {
                putchar('L');
                s--;
            }
            else if (s < f)
            {
                putchar('R');
                s++;
            }
            curT++;
        }           
        int next;
        if (s < f)
            next = s + 1;
        if (s > f)
            next = s - 1;
        if (s != f)
        {
            if ((s < l || s > r) && (next < l || next > r))
            {             
                if (next > s)
                    putchar('R');
                else
                    putchar('L');
                s = next;
            }
            else
                putchar('X');
        }
        curT = t + 1;
    }         

    while (s != f)
    {
        if (s > f)
        {
            putchar('L');
            s--;
        }
        else if (s < f)
        {
            putchar('R');
            s++;
        }
    }


    return 0;
}