#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;

ll arr[maxn],dp[maxn];

int main()
{
    int n,ans=0;
    cin>>n;
    ans+=n/100;
    n%=100;
    ans+=n/20;
    n%=20;
    ans+=n/10;
    n%=10;
    ans+=n/5;
    n%=5;
    ans+=n;
    cout<<ans;
}