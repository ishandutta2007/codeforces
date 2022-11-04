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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
const ll Mod=1000000007;
long long Mode(long long a, long long b)
{
    long long sum = 1;
    while (b) {
        if (b & 1) {
            sum = (sum * a) % Mod;
            b--;
        }
        b /= 2;
        a = a * a % Mod;
    }
    return sum%Mod;
}

ll a[10000005];
int main()
{
    sync
    ll x,n;
    cin>>x>>n;
    int s=0;
    ll ss=sqrt(x)+2;
    ll sss=2;
    while(x!=1&&sss<=ss)
    {
        if(x%sss==0)
        {
            a[s++]=sss;
            while(x%sss==0)
                x/=sss;
        }
        sss++;
    }
    if(x!=1)
        a[s++]=x;
    ll sum=1,d,w;
//    for(int i=0;i<s;i++)
//    {
//        cout<<a[i]<<endl;
//    }
    for(int i=0;i<s;i++)
    {
        d=0;
        w=n;
//        cout<<w<<endl;
        while(w>=a[i])
        {
            d+=(w/a[i]);
            w/=a[i];
        }
//        cout<<a[i]<<' ';
//        cout<<Mode(a[i],d)<<endl;
        if(a[i]!=0)
        sum=(sum*Mode(a[i],d))%Mod;
    }
    cout<<sum%Mod<<endl;
    return 0;
}