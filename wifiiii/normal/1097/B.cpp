#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;

int a[55],b[55];
int ans[666],n;
void dfs(int t)
{
    if(t>n)
    {
        int sum = 0;
        for(int i=1;i<=n;++i) sum+=b[i];

        ans[(sum%360+360)%360]++;
    }
    else
    {
        b[t]=a[t];
        dfs(t+1);
        b[t]=-a[t];
        dfs(t+1);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    dfs(1);
    if(ans[0]) cout<<"YES\n";
    else cout<<"NO\n";
}