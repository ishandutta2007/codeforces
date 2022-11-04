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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll A,B,C;

ll f[60];

int main()
{
    sync;
    int t;
    cin>>t;
    f[1]=1;
    int cnt;
    for(int i=2;i<=30;i++)
    {
        f[i]=4ll*f[i-1];
        if(f[i]>1e16)
        {
            cnt=i;
            break;
        }
    }
//    for(int i=1;i<=20;i++)
//    {
//        f[i]--;
//    }
    while(t--)
    {
        ll x;
        cin>>x;
        A=0,B=0,C=0;
        int p=upper_bound(f+1,f+cnt,x)-f-1;
        ll X=(x-f[p])/3ll+f[p];
        ll D=X;
        ll pos=1ll;
        while(X)
        {
            ll d=X%4;
            if(d==1)
            {
                A+=1ll*pos;
                B+=2ll*pos;
                C+=3ll*pos;
            }
            else if(d==2)
            {
                A+=2ll*pos;
                B+=3ll*pos;
                C+=1ll*pos;
            }
            else if(d==3)
            {
                A+=3ll*pos;
                B+=1ll*pos;
                C+=2ll*pos;
            }
            pos*=4ll;
            X/=4;
        }
        if(x%3ll==1)
        {
            cout<<A<<endl;
        }
        else if(x%3ll==2)
        {
            cout<<B<<endl;
        }
        else
            cout<<C<<endl;
        
    }
    return 0;
}