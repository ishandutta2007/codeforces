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
#define point complex<double>
#define xx first
#define yy second

const int maxn=10005;
map<long long, int> ind;

long long get_hash(char *c)
{
    long long ans=0;
    for(int i=0; c[i]; i++)
        ans=ans*997+c[i];
    return ans;
}

char names[maxn][30];
long long hashes[maxn];

int good[maxn], cnt[maxn], ans[maxn];

vector<int> g[maxn];
int vv[maxn], top, n;

void get_ans(int s)
{
    int i, j, tmp, tmp1, mx, mxn;
    for(i=0; i<(int)g[s].size(); i++)
        good[g[s][i]]=s;
    good[s]=s;
    for(i=0; i<(int)g[s].size(); i++)
    {
        tmp=g[s][i];
        for(j=0; j<(int)g[tmp].size(); j++)
        {
            tmp1=g[tmp][j];
            if (good[tmp1]!=s)
                cnt[tmp1]++;
        }
    }
    top=0;
    for(i=0; i<n; i++)
        if (cnt[i])
        {
            vv[top++]=cnt[i];
            cnt[i]=0;
        }
    mx=0, mxn=0;
    for(i=0; i<top; i++)
        if (vv[i]>mx)
        {
            mx=vv[i];
            mxn=1;
        }
        else if (vv[i]==mx)
            mxn++;
    if (mx==0)
        ans[s]=n-(int)g[s].size()-1;
    else 
        ans[s]=mxn;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int m, i, ind1, ind2;
    long long v1, v2;
    char c1[30], c2[30];
    string s1, s2;
    scanf("%d", &m);
    for(i=0; i<m; i++)
    {
        scanf("%s %s", &c1, &c2);
        v1=get_hash(c1);
        v2=get_hash(c2);
        if (ind.find(v1)==ind.end())
        {
            ind[v1]=n;
            strcpy(names[n], c1);
            n++;
        }
        if (ind.find(v2)==ind.end())
        {
            ind[v2]=n;
            strcpy(names[n], c2);
            n++;
        }
        ind1=ind[v1];
        ind2=ind[v2];
        g[ind1].pb(ind2);
        g[ind2].pb(ind1);
    }
    for(i=0; i<n; i++)
        good[i]=-1;
    for(i=0; i<n; i++)
        get_ans(i);
    printf("%d\n", (int)ind.size());
    for(map<long long, int>::iterator it=ind.begin(); it!=ind.end(); it++)
        printf("%s %d\n", names[it->second], ans[it->second]);
}