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
const int maxn=2005;

ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    sync;
    int t;
    cin>>t;
    ll r,d,k;
    ll a,b,c,s,aa,bb,sum;
    while(t--)
    {
        cin>>r>>d>>k;
        a=min(r,d);
        b=max(r,d);
        c=gcd(a,b);
        s=a*b/c;
        bb=s/b-1;
        aa=s/a-1;
        if(r==d)
        {
            cout<<"OBEY"<<endl;
            continue;
        }
        if(aa%(bb+1)==0)
            sum=aa/(bb+1);
        else
            sum=aa/(bb+1)+1;
//        cout<<aa<<' '<<bb<<' '<<sum<<' '<<k<<' ';
        if(sum>=k)
            cout<<"REBEL"<<endl;
        else
            cout<<"OBEY"<<endl;
    }
    return 0;
        
}