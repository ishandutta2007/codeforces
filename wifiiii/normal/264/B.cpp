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

const int maxn = 100005;
int prime[maxn],np[maxn],tot=0;
void init()
{
    for(int i=2;i<=maxn;++i)
    {
        if(!np[i]) prime[++tot] = i;
        for(int j=1;j<=tot;++j)
        {
            if(i*prime[j]>maxn) break;
            np[i*prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}
int dp[100005];
map<int,int> mp; //mapi
int main()
{
    init();
    int n;
    int ans = 0;
    cin>>n;
    for(int i=1;i<=n;++i) dp[i]=1;
    for(int i=1;i<=n;++i)
    {
        int tmp;cin>>tmp;
        for(int j=1;j<=tot;++j)
        {
            if(prime[j]*prime[j]>tmp) break;
            if(tmp % prime[j] == 0)
            {
                if(mp.count(prime[j])) dp[i]=max(dp[i], dp[mp[prime[j]]]+1);
                mp[prime[j]] = i;
                while(tmp % prime[j] == 0) tmp /= prime[j];
            }
        }
        if(tmp > 1)
        {
            if(mp.count(tmp)) dp[i]=max(dp[i], dp[mp[tmp]]+1);
            mp[tmp] = i;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}