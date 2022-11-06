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

set <int> st;
map <int, int> mp;
int les[505][505], dp[505][505], prv[505][505][2];
vector <int> ind[1005];
int v[2][505], v1[2][505];
stack<int> ans;

int main()
{   
    int n[2], i, j, i1, j1, k1, k2, sz, tmp, mx=0, mxi, mxj;
    set<int>::iterator it;
    for(j=0; j<2; j++)
    {
        scanf("%d", &n[j]);
        for(i=0; i<n[j]; i++)
        {
            scanf("%d", &v1[j][i]);
            st.insert(v1[j][i]);
        }
    }
    for(i=0, it=st.begin(); it!=st.end(); it++, i++)
        mp[*it]=i;
    for(j=0; j<2; j++)
        for(i=0; i<n[j]; i++)
            v[j][i]=mp[v1[j][i]];
    for(i=1; i<n[0]; i++)
        for(j=0; j<i; j++)
            if (v[0][j]<v[0][i])
                les[i][v[0][j]]=j;
    for(i=0; i<n[1]; i++)
        ind[v[1][i]].push_back(i);
    for(i=0; i<n[0]; i++)
        for(j=0; j<n[1]; j++)
            if (v[0][i]==v[1][j])
            {
                dp[i][j]=1;
                prv[i][j][0]=prv[i][j][1]=-1;
                for(k1=0; k1<i; k1++)
                {
                    tmp=v[0][k1];
                    if (tmp>=v[0][i]) continue;
                    sz=ind[tmp].size();
                    for(k2=0; k2<sz; k2++)
                    {
                        if (ind[tmp][k2]>=j) break;
                        if (dp[k1][ind[tmp][k2]]>=dp[i][j])
                        {
                            dp[i][j]=dp[k1][ind[tmp][k2]]+1;
                            prv[i][j][0]=k1;
                            prv[i][j][1]=ind[tmp][k2];
                        }
                    }
                }
            }
    mxi=mxj=-1;
    for(i=0; i<n[0]; i++)
        for(j=0; j<n[1]; j++)
            if (dp[i][j]>mx)
            {
                mx=dp[i][j];
                mxi=i; mxj=j;
            }
    printf("%d\n", mx);
    for(i=mxi, j=mxj; i!=-1; )
    {
        ans.push(v1[0][i]);
        i1=prv[i][j][0];
        j1=prv[i][j][1];
        i=i1; j=j1;
    }
    while(!ans.empty())
    {
        printf("%d ", ans.top());
        ans.pop();
    }
}