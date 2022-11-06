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

int m[100005], top, next[100005], n;
int g[100005][11], tp[100005];
vector<int> vc[100005];
long long hsh[100005], st[100005], p=1000007;

void fill_hsh()
{
    int i;
    for(i=1, st[0]=1, hsh[0]=m[0]; i<n; i++)
    {
        st[i]=st[i-1]*p;
        hsh[i]=hsh[i-1]+m[i]*st[i];
    }
    return;
}

int main()
{      
    int i, s, j, k;
    long long tmp1, tmp2;
    map<int, int> mp;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &m[i]);
        if (mp.find(m[i])==mp.end())
            mp[m[i]]=top++;
    }
    for(i=0; i<n; i++)
        g[mp[m[i]]][tp[mp[m[i]]]++]=i;
    fill_hsh();
    for(i=0; i<top; i++)
    {
        for(j=0; j<tp[i]-1; j++)
            next[g[i][j]]=g[i][j+1];
        next[g[i][j]]=-1;
    }
    for(i=0; i<n; i++)
        for(j=i; next[j]!=-1; j=next[j])
            if (next[j]-j<=n/2)
                vc[next[j]-j].push_back(j);
    s=0;
    for(i=1; i<=n/2; i++)
        for(j=0; j<(int)vc[i].size(); j++)
            if (vc[i][j]>=s && vc[i][j]+2*i<=n)
            {
                tmp1=hsh[vc[i][j]+i-1];
                if (vc[i][j]) tmp1-=hsh[vc[i][j]-1];
                tmp2=hsh[vc[i][j]+2*i-1];
                tmp2-=hsh[vc[i][j]+i-1];
                if (tmp1*st[i]==tmp2)
                    s=i+vc[i][j];
            }
    printf("%d\n", n-s);
    for(i=s; i<n; i++) printf("%d ", m[i]);
}