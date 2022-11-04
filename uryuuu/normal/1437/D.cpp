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
const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[maxn];
int b[maxn];
int s[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=1;
        }
        int num=1,sum=0;
        int dep=1;
        for(int i=3;i<=n;i++)
        {
            if(a[i]>a[i-1])
            {
                b[i]=b[i-1]+1;
                b[i-1]=0;
            }
        }
        int cnt=0;
        for(int i=2;i<=n;i++)
        {
            if(b[i]>0)
                s[++cnt]=b[i];
        }
        for(int i=1;i<=cnt;i++)
        {
//            cout<<s[i]<<' ';
            if(num==0)
            {
                dep++;
                num=sum;
                sum=0;
            }
            num--;
            sum+=s[i];
        }
        cout<<dep<<endl;
    }
    
    
    return 0;
}