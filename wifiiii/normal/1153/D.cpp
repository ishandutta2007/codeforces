#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long ll;

int a[300005];
vector<int> g[300005];
int cnt;
int dfs(int u,int tag)
{
    if(!g[u].size())
    {
        cnt++;
        return 1;
    }
    int ret = 0;
    if(tag) ret = 1e9;
    for(int v:g[u])
    {
        if(tag)
        {
            ret = min(ret, dfs(v, a[v]));
        }
        else
        {
            ret += dfs(v, a[v]);
        }
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=2;i<=n;++i)
    {
        int fa;
        cin>>fa;
        g[fa].push_back(i);
    }
    int son = dfs(1,a[1]);
    cout << cnt - son + 1 << endl;
}