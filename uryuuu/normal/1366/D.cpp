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
//#include<unordered_map>
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
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
//const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[500005];

int num;
const ll maxn=10000005;
int prime[maxn];      //
bool sf[maxn];        //sf[i]i1maxn
void sushu()
{         // 
    num=0;        //num 
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


int gcd(int a,int b)
{
    if(a==0)
        return 1;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int b[500005][5];
int main()
{
//    sync;
    int n;
    sushu();
//    cin>>n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
//        cin>>a[i];
        scanf("%d",&a[i]);
        b[i][1]=1;
        if(sf[a[i]]==1)
            continue;
        int x=a[i];
        for(int j=1;j<=num;j++)
        {
            if(sf[a[i]]==1)
            {
                b[i][1]*=a[i];
                if(gcd(x,(b[i][0]+b[i][1]))==1)
                    b[i][3]=1;
                break;
            }
            if(prime[j]>a[i])
                break;
            if(a[i]%prime[j]==0)
            {
//                cout<<prime[j]<<' ';
                if(b[i][0])
                {
                    b[i][1]*=prime[j];
                    if(gcd(x,(b[i][0]+b[i][1]))>1)
                    {
                        while(a[i]%prime[j]==0)
                        {
                            a[i]/=prime[j];
                        }
                    }
                    else
                    {
                        b[i][3]=1;
                        break;
                    }
                }
                else
                {
                    b[i][0]=prime[j];
                    while(a[i]%prime[j]==0)
                    {
                        a[i]/=prime[j];
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(b[i][3]==0)
        {
            b[i][0]=-1;
            b[i][1]=-1;
        }
    }
    for(int i=1;i<=n;i++)
    {
//        cout<<b[i][0]<<' ';
        printf("%d ",b[i][0]);
    }
    puts("");
    for(int i=1;i<=n;i++)
    {
//        cout<<b[i][0]<<' ';
        printf("%d ",b[i][1]);
    }
    puts("");
    
    return 0;
}
//1
//7817670