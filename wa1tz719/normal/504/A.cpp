#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<sstream>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int maxn=100005;
int degree[maxn],xors[maxn];
void dfs(int x)
{
    cout<<x<<" "<<xors[x]<<endl;
    xors[xors[x]]^=x;
    degree[x]--;
    degree[xors[x]]--;
    if (degree[xors[x]]==1) dfs(xors[x]);
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    int i;
    long long sum=0;
    for (i=0;i<n;i++)
    {
        scanf("%d%d",&degree[i],&xors[i]);
        sum+=degree[i];
    }
    cout<<sum/2<<endl;
    for (i=0;i<n;i++)
    {
        if (degree[i]==1) dfs(i);
    }
    return 0;
}