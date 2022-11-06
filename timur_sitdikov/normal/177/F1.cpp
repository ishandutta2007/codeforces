#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int g[25][25];
vector <int> v, tmp;
vector<vector<int>> pers[6], ss[6];

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, m, i, j, k, k1, a, b, c, ind, f, fl, cur;
    scanf("%d %d %d", &n, &m, &ind);
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        g[--a][--b]=c;
    }
    for(i=0; i<(1<<n); i++)
    {
        tmp.clear();
        for(j=0; j<32; j++)
            if (i&(1<<j)) tmp.push_back(j);
        for(j=1, f=1; j<=(int)tmp.size(); j++) f*=j;
        ss[tmp.size()].push_back(tmp);
        for(j=0; j<f; j++)
        {
            next_permutation(tmp.begin(), tmp.end());
            pers[tmp.size()].push_back(tmp);
            /*fl=0; cur=0;
            for(k=0; k<(int)tmp.size(); k++)
                if (!g[k][tmp[k]]) fl=1;
                else cur+=g[k][tmp[k]];
            v.push_back(cur);*/
        }
    }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<(int)ss[i].size(); j++)
            for(k=0; k<(int)pers[i].size(); k++)
            {
                fl=0; cur=0;
                for(k1=0; k1<i; k1++)
                    if (!g[ss[i][j][k1]][pers[i][k][k1]]) fl=1;
                    else cur+=g[ss[i][j][k1]][pers[i][k][k1]];
                if (!fl) v.push_back(cur);
            }
    }
    sort(v.begin(), v.end());
    printf("%d", v[--ind]);
}