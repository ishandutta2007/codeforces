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

string st[6];
int len[6];

char vv[720][40][40];
int top;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, n, j, k, m[6], mn, f;
    for(i=0; i<6; i++)
        cin >> st[i];
    sort(st, st+6);
    for(i=0; i<6; i++)
        m[i]=i;
    for(k=0; k<720; next_permutation(st, st+6), k++)
    {
        for(i=0; i<6; i++)
            len[i]=st[i].length();
        if (st[3].length()<=st[0].length()+1 || st[2].length()<=st[1].length()+1 ||
            st[0].length()+st[5].length()!=st[3].length()+1 ||
            st[1].length()+st[4].length()!=st[2].length()+1)
            continue;
        if (st[1][0]!=st[0][0] || st[4][len[4]-1]!=st[5][len[5]-1])
            continue;
        if (st[0][len[0]-1]!=st[2][0] || st[1][len[1]-1]!=st[3][0])
            continue;
        if (st[3][len[3]-1]!=st[4][0] || st[2][len[2]-1]!=st[5][0])
            continue;
        if (st[2][len[1]-1]!=st[3][len[0]-1])
            continue;
        for(i=0; i<len[2]; i++)
        {
            for(j=0; j<len[3]; j++)
                vv[top][i][j]='.';
            vv[top][i][j]=0;
        }
        for(j=0; j<len[0]; j++)
            vv[top][0][j]=st[0][j];
        for(j=0; j<len[3]; j++)
            vv[top][len[1]-1][j]=st[3][j];
        for(j=len[0]-1; j<len[3]; j++)
            vv[top][len[2]-1][j]=st[5][j-len[0]+1];
        for(i=0; i<len[1]; i++)
            vv[top][i][0]=st[1][i];
        for(i=0; i<len[2]; i++)
            vv[top][i][len[0]-1]=st[2][i];
        for(i=len[1]-1; i<len[2]; i++)
            vv[top][i][len[3]-1]=st[4][i-len[1]+1];
        top++;
        /*for(i=0; i<len[2]; i++)
            printf("%s\n", vv[i]);
        return 0;*/
    }
    if (!top)
    {
        printf("Impossible");
        return 0;
    }
    for(mn=0, k=1; k<top; k++)
    {
        f=0;
        for(i=0; i<40; i++)
            for(j=0; j<40; j++)
                if (vv[k][i][j]<vv[mn][i][j])
                {
                    f=1;
                    goto ll;
                }
                else if (vv[k][i][j]>vv[mn][i][j])
                    goto ll;
ll:     if (f)
            mn=k;
    }
    for(i=0; vv[mn][i][0]; i++)
        printf("%s\n", vv[mn][i]);
    return 0;
    
}