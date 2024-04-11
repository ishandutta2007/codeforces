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


int a[maxn];
struct node
{
    int x,y;
}ans[maxn];


int main()
{
    sync;
    int t;
    int n;
    a[1]=3;
    for(int i=2;i<=5;i++)
    {
        a[i]=a[i-1]*a[i-1];
//        cout<<a[i]<<' ';
    }

    cin>>t;
    while(t--)
    {
        cin>>n;
        int pos=1;
        for(int i=1;i<=5;i++)
        {
            if(n>a[i])
                pos=i;
        }
        
        if(n==3)
        {
            cout<<2<<endl;
            cout<<3<<' '<<2<<endl;
            cout<<3<<' '<<2<<endl;
            continue;
        }
        
        int cnt=0;
        int R=n;
        for(int i=n-1;i>3;i--)
        {
            if(i==a[pos])
            {
                ans[++cnt].x=R;
                ans[cnt].y=a[pos];
                ans[++cnt].x=R;
                ans[cnt].y=a[pos];
                R=a[pos];
                pos--;
            }
            else
            {
                ans[++cnt].x=i;
                ans[cnt].y=R;
            }
        }
        ans[++cnt].x=R;
        ans[cnt].y=3;
        ans[++cnt].x=R;
        ans[cnt].y=3;
        ans[++cnt].x=3;
        ans[cnt].y=2;
        ans[++cnt].x=3;
        ans[cnt].y=2;
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
            cout<<ans[i].x<<' '<<ans[i].y<<endl;
    }
    
    
    return 0;
}