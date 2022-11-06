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

string num, ans[2];
int ct[10][10][2], ct0[10], good[10], nol[10], d1[10], d2[10], tmp[10];

int main()
{   
    int i, j, k, lim, mx=-1, maxi;
    cin >> num;
    if (num=="0")
    {
        printf("0\n0");
        return 0;
    }
    for(i=0; i<num.length(); i++)
        ct0[num[i]-'0']++;
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            ct[i][j][0]=ct[i][j][1]=ct0[j];
    for(i=0; i<10; i++)
    {
        d1[i]=(10-i)%10;
        d2[i]=9-i;
    }
    for(i=1; i<10; i++)
    {
        if (ct[i][i][0]==0) 
        {
            good[i]=-1;
            continue;
        }
        if (ct[i][d1[i]][0]==0)
        {
            good[i]=0;
            nol[i]=ct[i][0][0];
            continue;
        }
        good[i]=1;
        ct[i][i][0]--;
        ct[i][d1[i]][1]--;
        for(j=0; j<10; j++)
        {
            lim=min(ct[i][j][0], ct[i][d2[j]][1]);
            ct[i][j][0]-=lim;
            ct[i][d2[j]][1]-=lim;
            tmp[j]=lim;
            good[i]+=lim;
        }
        nol[i]=min(ct[i][0][0], ct[i][0][1]);
        for(j=0; j<10; j++)
        {
            ct[i][j][0]+=tmp[j];
            ct[i][d2[j]][1]+=tmp[j];
        }
        ct[i][i][0]++;
        ct[i][d1[i]][1]++;
    }
    for(i=1; i<10; i++) 
        if (good[i]!=-1 && good[i]+nol[i]>mx)
        {
            maxi=i;
            mx=good[i]+nol[i];
        }
    for(i=0; i<nol[maxi]; i++)
    {
        ans[0].push_back('0');
        ans[1].push_back('0');
        ct[maxi][0][0]--;
        ct[maxi][0][1]--;
    }
    if (good[maxi])
    {
        ans[0].push_back(maxi+'0');
        ct[maxi][maxi][0]--;
        ans[1].push_back(d1[maxi]+'0');
        ct[maxi][d1[maxi]][1]--;
        for(i=0; i<10; i++)
        {
            lim=min(ct[maxi][i][0], ct[maxi][d2[i]][1]);
            for(j=0; j<lim; j++)
            {
                ans[0].push_back(i+'0');
                ans[1].push_back(d2[i]+'0');
                ct[maxi][i][0]--;
                ct[maxi][d2[i]][1]--;
            }
        }
        for(k=0; k<2; k++)
            for(i=0; i<10; i++)
                for(j=0; j<ct[maxi][i][k]; j++)
                    ans[k].push_back(i+'0');
    }
    else
    {
        ans[0].push_back(maxi+'0');
        ct[maxi][maxi][0]--;
        for(k=0; k<2; k++)
            for(i=0; i<10; i++)
                for(j=0; j<ct[maxi][i][k]; j++)
                    ans[k].push_back(i+'0');
    }
    reverse(ans[0].begin(), ans[0].end());
    reverse(ans[1].begin(), ans[1].end());
    cout << ans[0] << endl << ans[1];
}