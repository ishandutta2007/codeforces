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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair

int c[15][15], c1[15][15];

pair<int, int> coord(string &s)
{
    pair<int, int> tmp;
    tmp.first=s[0]-'a'+1;
    tmp.second=s[1]-'0';
    return tmp;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s[4];
    pair<int ,int> pr;
    int i, j, k, l, t, f;
    for(i=0; i<4; i++)
    {
        cin >> s[i];
        pr=coord(s[i]);
        c[pr.first][pr.second]=i+2;
    }
    for(i=0; i<10; i++)
    {
        c[i][0]=c[0][i]=c[i][9]=c[9][i]=10;
        c1[i][0]=c1[0][i]=c1[i][9]=c1[9][i]=1;
    }
    for(i=1; i<=8; i++)
        for(j=1; j<=8; j++)
            if (c[i][j]==2 || c[i][j]==3)
            {
                for(k=1; c[i][j+k]<2 || c[i][j+k]==5; k++)
                    c1[i][j+k]++;
                if (c[i][j+k]!=10)
                    c1[i][j+k]++;
                for(k=1; c[i][j-k]<2 || c[i][j-k]==5; k++)
                    c1[i][j-k]++;
                if (c[i][j-k]!=10)
                    c1[i][j-k]++;
                for(k=1; c[i+k][j]<2 || c[i+k][j]==5; k++)
                    c1[i+k][j]++;
                if (c[i+k][j]!=10)
                    c1[i+k][j]++;
                for(k=1; c[i-k][j]<2 || c[i-k][j]==5; k++)
                    c1[i-k][j]++;
                if (c[i-k][j]!=10)
                    c1[i-k][j]++;
            }
            else if (c[i][j]==4)
            {
                for(k=-1; k<=1; k++)
                    for(l=-1; l<=1; l++)
                        c1[i+k][j+l]++;
            }
    for(i=1; i<=8; i++)
        for(j=1; j<=8; j++)
            if (c[i][j]==5)
            {
                if (!c1[i][j])
                {
                    printf("OTHER");
                    return 0;
                }
                for(k=-1; k<=1; k++)
                    for(l=-1; l<=1; l++)
                        if (!c1[i+k][j+l])
                        {
                            printf("OTHER");
                            return 0;
                        }
                printf("CHECKMATE");
                return 0;
            }
    
}