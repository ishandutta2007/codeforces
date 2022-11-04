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

ll a[maxn];
ll b[maxn],c[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int bnt=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]%2==0)
                b[++bnt]=a[i];
            else
                c[++cnt]=a[i];
        }
        b[0]=0ll;
        c[0]=0ll;
        ll sb=0,sc=0;
        sort(b+1,b+bnt+1);
        sort(c+1,c+cnt+1);
        for(int i=1;i<=n;i++)
        {
            if(i%2)
            {
                if(bnt>0&&b[bnt]>=c[cnt])
                {
                    sb+=1ll*b[bnt];
                    bnt--;
                }
                else
                {
                    cnt--;
                }
            }
            else
            {
                if(cnt>0&&c[cnt]>=b[bnt])
                {
                    sc+=1ll*c[cnt];
                    cnt--;
                }
                else
                {
                    bnt--;
                }
            }
        }
        if(sb>sc)
            cout<<"Alice"<<endl;
        else if(sb<sc)
            cout<<"Bob"<<endl;
        else
            cout<<"Tie"<<endl;
        
    }
    
    return 0;
}