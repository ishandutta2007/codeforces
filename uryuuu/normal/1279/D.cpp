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
const ll  Mod=998244353;

ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res;
}

ll b[maxn*10],c[maxn*10],v[maxn*10];
vector<ll>a[maxn*10];

int main()
{
    sync;
    int n,m;
    cin>>n;
    int kk;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        c[i]=m;
        for(int j=0;j<m;j++)
        {
            cin>>kk;
            v[kk]++;
            a[i].push_back(kk);
        }
    }
    ll p=0;
    ll nn=ksm(n,Mod-2);
    nn=nn*nn%Mod;
    ll cm;
    for(int i=0;i<n;i++)
    {
        cm=ksm(c[i],Mod-2);
        for(int j=0;j<a[i].size();j++)
            p=(p+(v[a[i][j]]*cm+Mod)%Mod+Mod)%Mod;
    }
    p=(p*nn+Mod)%Mod;
    cout<<p<<endl;
    return 0;
}