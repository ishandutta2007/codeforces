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

string names[12];

int a[12][105], b[12][105], c[12][105];
pair<int, int> mas[105];

int main()
{   

    int n, m, k, i, j, l, mx=0, cur, top, tmp, tmp1;
    scanf("%d %d %d", &n, &m, &k);
    for(i=0; i<n; i++)
    {
        cin >> names[i];
        for(j=0; j<m; j++)
            scanf("%d %d %d", &a[i][j], &b[i][j], &c[i][j]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if (i==j) continue;
            top=0;
            cur=0;
            for(l=0; l<m; l++)
                if (a[i][l]<b[j][l]) 
                {
                    mas[top++]=make_pair(b[j][l]-a[i][l], c[i][l]);
                }
            sort(mas, mas+top);
            reverse(mas, mas+top);
            tmp=tmp1=0;
            for(l=0; l<top; l++)
            {
                tmp1=max(min(mas[l].second, k-tmp), 0);
                cur+=tmp1*mas[l].first;
                tmp+=tmp1;
            }
            if (cur>mx) mx=cur;
        }
    printf("%d", mx);
}