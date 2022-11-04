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

ll a[maxn],b[maxn],v[maxn],p[maxn];
int main()
{
    sync;
    int t;
    cin>>t;
    int n,m;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            v[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>b[i];
            v[b[i]]=i;
        }
        ll sum=0;
        int d=2e9;
        for(ll i=n;i>=1;i--)
        {
            if(v[a[i]]!=0)
            {
               if(v[a[i]]>d)
                    sum++;
                else
                {
                    sum+=1ll*(2*(i-(v[a[i]]-1))-1);
                    d=v[a[i]];
                }
            }
                
        }
        cout<<sum<<endl;
    }
    return 0;
}