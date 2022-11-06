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

const int nmax=515;
map<int, set<int>> segs[2];
int num[nmax], x[nmax], y[nmax];

int dis(int x1, int y1, int x2, int y2)
{return abs(x1-x2)+abs(y1-y2);}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, n, m, a;
    cin >> n >> m;
    if (n&1) 
    {
        printf("NO");
        return 0;
    }
    for(i=0; i<n; i++)
        cin >> x[i] >> y[i];
    x[n]=x[0];
    y[n]=y[0];
    x[n+1]=x[1];
    y[n+1]=y[1];
    x[n+2]=x[2];
    y[n+2]=y[2];
    for(i=1; i<=m; i++)
    {
        cin >> a;
        segs[0][a].insert(i);
        segs[1][a].insert(i);
    }
    for(j=0; j<2; j++)
    {
        for(i=0; i<n; i+=2)
        {
            a=dis(x[i+j], y[i+j], x[i+j+1], y[i+j+1])+
              dis(x[i+j+2], y[i+j+2], x[i+j+1], y[i+j+1]);
            if (segs[j][a].empty()) break;
            num[i+j+1]=*(segs[j][a].begin());
            segs[j][a].erase(segs[j][a].begin());
        }
        if (i==n)
        {
            printf("YES\n");
            num[0]=num[n];
            if (num[n+1]) 
                num[1]=num[n+1];
            for(i=0; i<n; i++)
                if (!num[i]) cout << "-1" << endl;
                else cout << num[i] << endl;
            return 0;
        }
        for(i=0; i<n; i++) num[i]=0;
    }
    printf("NO");
}