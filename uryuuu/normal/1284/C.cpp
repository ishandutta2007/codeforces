//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll  Mod=998244353;

int a[maxn],b[maxn];

ll s[300005];

int main()
{
    sync;
    ll n,m;
    cin>>n>>m;
    s[0]=1;
    for(int i=1;i<=n;i++)
    {
        s[i]=(s[i-1]*i)%m;
    }
    ll sum=s[n]%m;
    for(int i=1;i<n;i++)
    {
        sum=(sum+((s[i]*(((i+1))%m)%m)*(i+1)%m)*s[n-i]%m)%m;
    }
    cout<<sum<<endl;
    return 0;
}