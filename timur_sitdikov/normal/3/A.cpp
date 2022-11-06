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

char c[10][10], prv[10][10][2], col[10][10], dis[10][10];

void bfs(int i, int j)
{
    int i1, j1, i2, j2;
    queue <pair <int, int> > qq;
    qq.push(make_pair(i, j));
    col[i][j]=1;
    while(!qq.empty())
    {
        i=qq.front().first;
        j=qq.front().second;
        qq.pop();
        for(i1=-1; i1<2; i1++)
            for(j1=-1; j1<2; j1++)
            {
                i2=i+i1;
                j2=j+j1;
                if (i2>0 && i2<9 && j2>0 && j2<9 && !col[i2][j2])
                {
                    prv[i2][j2][0]=i;
                    prv[i2][j2][1]=j;
                    col[i2][j2]=1;
                    dis[i2][j2]=dis[i][j]+1;
                    qq.push(make_pair(i2, j2));
                }   
            }
    }
}



int main()
{   

    char s[3], f[3];
    string ans;
    int i, j, di, dj, si, sj, fi, fj;
    scanf("%s %s", &s, &f);
    si=s[1]-'0';
    sj=s[0]-'a'+1;
    fi=f[1]-'0';
    fj=f[0]-'a'+1;
    bfs(fi, fj);
    printf("%d\n", dis[si][sj]);
    for(i=si, j=sj; i!=fi || j!=fj;)
    {
        di=-i+prv[i][j][0];
        dj=-j+prv[i][j][1];
        if (dj==1) ans.push_back('R');
        if (dj==-1) ans.push_back('L');
        if (di==1) ans.push_back('U');
        if (di==-1) ans.push_back('D');
        cout << ans << endl;
        ans.clear();
        i+=di;
        j+=dj;

    }
}