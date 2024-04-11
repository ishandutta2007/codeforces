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

const int maxn=30000, maxlen=30;
map<string, int> mp[35];
string st[35];
int offset[35];
long long sum[maxn][2], cost[maxn];
char good[maxn], col[maxn];
vector<int> g[30000];
set <string> used;

void dfs(int s)
{
    int i, tmp;
    col[s]=1;
    if (!g[s].size())
        return;
    for(i=0; i<(int)g[s].size(); i++)
    {
        tmp=g[s][i];
        if (!col[tmp])
            dfs(tmp);
        if (!good[tmp])
            good[s]=1;
    }
    for(i=0; i<(int)g[s].size(); i++)
    {
        tmp=g[s][i];
        if (good[tmp]==good[s])
            continue;
        if (sum[s][0]<cost[tmp]+sum[tmp][1])
        {
            sum[s][0]=cost[tmp]+sum[tmp][1];
            sum[s][1]=sum[tmp][0];
        }
        else if (sum[s][0]==cost[tmp]+sum[tmp][1])
        {
            if (sum[s][1]>sum[tmp][0])
                sum[s][1]=sum[tmp][0];
        }
    }
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, k;
    long long mx, tmp_sum;
    string tmp;
    map<string, int>::iterator it, it1;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> st[i];
    for(i=0; i<n; i++)
    {
        used.clear();
        for(j=0; j<(int)st[i].length(); j++)
        {
            tmp="";
            for(k=j; k<(int)st[i].length(); k++)
            {
                tmp.pb(st[i][k]);
                if (used.find(tmp)==used.end())
                {
                    mp[k-j+1][tmp]++;
                    used.insert(tmp);
                }
            }
        }
    }
    offset[1]=1;
    for(i=0; i<mp[1].size(); i++)
        g[0].pb(i+1);
    for(i=1; i<maxlen; i++)
    {
        offset[i+1]=offset[i]+mp[i].size();
        for(j=0, it=mp[i].begin(); it!=mp[i].end(); it++, j++)
        {
            for(k=0, it1=mp[i+1].begin(); it1!=mp[i+1].end(); it1++, k++)
            {
                if (it->first==it1->first.substr(0, i) || 
                    it->first==it1->first.substr(1, i))
                    g[offset[i]+j].pb(offset[i+1]+k);
            }
        }
    }
    for(i=1; i<=maxlen; i++)
        for(j=0, it=mp[i].begin(); it!=mp[i].end(); it++, j++)
        {
            mx=tmp_sum=0;
            for(k=0; k<it->first.length(); k++)
            {
                mx=max(mx, (long long)(it->first[k]-'a'+1));
                tmp_sum+=(long long)(it->first[k]-'a'+1);
            }
            cost[offset[i]+j]=mx*tmp_sum+it->second;
        }
    dfs(0);
    if (good[0])
        printf("First\n");
    else printf("Second\n");
    cout << sum[0][0] << " " << sum[0][1];
}