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
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=2010;
const ll Mod=1000000007;
//const ll Mod=998244353;
using namespace std;

ll prime[maxn];      //
bool sf[maxn];        //sf[i]i1maxn
void sushu()
{         // 
    ll num=0;        //num 
    memset(sf,true,sizeof(sf));
    sf[1] = false;
    sf[0] = false;  //1 0 
    for(int i = 2;i <= maxn; i ++)
    {          //1~maxn
        if(sf[i]) prime[++num] = i;      //
        for(int j = 1;j <= num;j ++)
        {       //num
            if(i * prime[j] > maxn) break; //
            sf[i * prime[j]] = false;      //...
            if(i % prime[j] == 0) break;   //
        }
    }
}


int a[maxn];
int b[maxn];

int  main()
{
    sync;
    int n,t;
    sushu();
    cin>>t;
    while(t--)
    {
        cin>>n;
        mm(b);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int k=1;
        int f;
        for(int i=1;i<=11;i++)
        {
            f=0;
            int x=prime[i];
            for(int j=1;j<=n;j++)
            {
                if(b[j]==0&&a[j]%x==0)
                {
                    b[j]=k;
                    f=1;
                }
            }
            if(f)
                k++;
        }
        k--;
        cout<<k<<endl;
        for(int i=1;i<=n;i++)
            cout<<b[i]<<' ';
        cout<<endl;
    }
    
    return 0;
}