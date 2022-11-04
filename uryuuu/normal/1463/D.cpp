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
            cin>>a[i];
        
        int L=0;
        int R=0;
        
//        int d=0;
        int s;
        
        s=2*n;
        for(int i=n;i>=1;i--)
        {
            if(a[i]<s)
            {
                L++;
                s-=2;
            }
            else
                s--;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            a[i]=2*n+1-a[i];
        }
        
        sort(a+1,a+n+1);
//        for(int i=1;i<=n;i++)
//            cout<<a[i]<<' ';
//        cout<<endl;
        
        s=2*n;
        for(int i=n;i>=1;i--)
        {
            if(a[i]<s)
            {
                R++;
                s-=2;
            }
            else
                s--;
        }
//        cout<<L<<' '<<R<<endl;
        
        cout<<L-(n-R)+1<<endl;
        
        
        
    }
    
    return 0;
}