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
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)2e3 + 100;
char table[N][N];
int ans[N];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    
    for (int i = 0; i < n; i++)
        scanf(" %s", table[i]);
    
    for (int i = 0; i < n; i++)
        for (int s = 0; s < m; s++)
        {
            if (table[i][s] == 'U')
            {
                if (i % 2 == 0)
                    ans[s]++;
            }
            else if (table[i][s] == 'R')
            {
                int t = i + s;
                if (t < m)
                    ans[t]++;
            }
            else if (table[i][s] == 'L')
            {
                int t = s - i;
                if (t >= 0)
                    ans[t]++;
            }
        }
    for (int i = 0; i < m; i++)
        printf("%d ", ans[i]);
    return 0;
}