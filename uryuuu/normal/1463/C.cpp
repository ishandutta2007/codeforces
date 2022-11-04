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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;


struct node
{
    ll t,x;
}a[maxn];

int main()
{
    sync;
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].t>>a[i].x;
        a[n+1].t=2e13;
        ll pre=0;
        ll lst=a[1].x;
        ll tm=a[1].t+abs(a[1].x);
        int ans=0;
        ll L,R;
        ll d;
        for(int i=2;i<=n;i++)
        {
            if(tm<=a[i].t)
                R=lst;
            else
            {
                d=tm-a[i].t;
                if(pre<=lst)
                    R=lst-d;
                else
                    R=lst+d;
            }
            
            d=tm-a[i-1].t;
            if(pre<=lst)
                L=lst-d;
            else
                L=lst+d;
            
            if(L<=a[i-1].x&&a[i-1].x<=R)
                ans++;
            else if(R<=a[i-1].x&&a[i-1].x<=L)
                ans++;
            
            
            if(tm<=a[i].t)
            {
                tm=1ll*a[i].t+1ll*abs(a[i].x-lst);
                pre=lst;
                lst=a[i].x;
            }
        }
        
        for(int i=n+1;i<=n+1;i++)
        {
            if(tm<=a[i].t)
                R=lst;
            else
            {
                d=tm-a[i].t;
                if(pre<=lst)
                    R=lst-d;
                else
                    R=lst+d;
            }
            
            d=tm-a[i-1].t;
            if(pre<=lst)
                L=lst-d;
            else
                L=lst+d;
            
            if(L<=a[i-1].x&&a[i-1].x<=R)
                ans++;
            else if(R<=a[i-1].x&&a[i-1].x<=L)
                ans++;
        }
        
        
        cout<<ans<<endl;
        
        
        
        
    }
    
    return 0;
}