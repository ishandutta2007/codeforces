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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=400050;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;



int a[200];

int main()
{
    sync;
    int n,t;
    cin>>n;
    rep(i,1,n)
    {
        cin>>a[i];
    }
    rep(i,2,n)
    {
        if(a[i]!=1&&a[i-1]!=1)
        {
            cout<<"Infinite"<<endl;
            return 0;
        }
    }
    cout<<"Finite"<<endl;
    int ans=0;
    rep(i,2,n)
    {
        if(a[i]!=1)
        {
            if(a[i]==2)
                ans+=3;
            else
                ans+=4;
        }
        else
        {
            if(a[i-1]==2)
                ans+=3;
            else
                ans+=4;
        }
    }
    rep(i,3,n)
    {
        if((a[i]==2&&a[i-2]==3))
            ans--;
    }
    cout<<ans<<endl;
    
    return 0;
}