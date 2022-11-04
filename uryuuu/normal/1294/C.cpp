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
const int maxn=105;
const ll Mod=1e9+7;



int main()
{
    sync;
    int t,n,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a=0;
        b=0;
        c=0;
        for(int i=2;i*i<n;i++)
        {
            if(n%i==0)
            {
                a=i;
                break;
            }
        }
        if(a==0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        n/=a;
        for(int i=a+1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                b=i;
                c=n/i;
                break;
            }
        }
        if(b==0||c==0||b==c||b==a||c==a)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<a<<' '<<b<<' '<<c<<endl;
        }
    }
    return 0;
}