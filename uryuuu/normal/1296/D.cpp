#include<iostream>
#include<stdio.h>
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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
const ll Mod=998244353;

ll s[maxn];

int main()
{
    sync;
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        s[i]=(s[i]-1)%(a+b)+1;
//        cout<<s[i]<<' ';
        if(s[i]<=a)
            s[i]=0;
        else
        {
            s[i]-=a;
            if(s[i]%a==0)
                s[i]=s[i]/a;
            else
                s[i]=s[i]/a+1;
        }
//        cout<<s[i]<<endl;
    }
    sort(s,s+n);
    ll sum=0,pos=0;
    for(int i=0;i<n;i++)
    {
//        cout<<s[i]<<' ';
        k-=s[i];
        if(k>=0)
            sum++;
        else
            break;
    }
    cout<<sum<<endl;
    return 0;
}