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
const int maxn=200005;
 
int a[maxn],dp[maxn],s[maxn];
int main()
{
    sync;
    int n,p,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>p>>k;
        for(int i=0;i<=n;i++)
            dp[i]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        s[0]=0;
        for(int i=1;i<=n;i++)
        {
            s[i]=s[i-1]+a[i];
        }
        ll da=0;
        ll sum=0;
        ll ss;
        for(int i=1;i<=k;i++)
        {
            sum=0;
            int pos=i+k-1;
            ll sss=upper_bound(s,s+i,p)-s-1;
            da=max(sss,da);
            int d=0;
            while(pos<=n)
            {
                d++;
                sum+=a[pos];
                if(sum>p)
                    break;
                ss=upper_bound(s,s+i,p-sum)-s-1;
                da=max(ss+d*k,da);
                pos+=k;
            }
        }
        cout<<da<<endl;
    }
    return 0;
}