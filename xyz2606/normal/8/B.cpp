#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <bitset>
#include <sstream>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define X first
#define Y second
const int INF = 1e9;
const int MN = 105;

bool mark[500][500];

char s[MN];

int dis[500][500];
int ask(pair<int, int> now)
{
    int res = INF;
    if(mark[now.X][now.Y]) res = min(res, dis[now.X][now.Y]);
    if(mark[now.X - 1][now.Y]) res = min(res, dis[now.X - 1][now.Y] + 1);
    if(mark[now.X + 1][now.Y]) res = min(res, dis[now.X + 1][now.Y] + 1);
    if(mark[now.X][now.Y - 1]) res = min(res, dis[now.X][now.Y - 1] + 1);
    if(mark[now.X][now.Y + 1]) res = min(res, dis[now.X][now.Y + 1] + 1);
    return res;
}

int main()
{
    scanf("%s", s);
    int l = strlen(s);
    pair<int, int> now =  make_pair(105, 105);
    mark[105][105] = 1;
    dis[105][105] = 0;
    
    int len = 0;
    for(int i = 0; i < l; ++i)
    {
        ++len;
        if(s[i] == 'U') now.Y += 1;
        if(s[i] == 'D') now.Y -= 1;
        if(s[i] == 'L') now.X -= 1;
        if(s[i] == 'R') now.X += 1;
        if(ask(now) < len) 
        {
            printf("BUG\n");
            return 0;
        }
        mark[now.X][now.Y] = 1;
        dis[now.X][now.Y] = len;
    }
    printf("OK\n");
    return 0;
}