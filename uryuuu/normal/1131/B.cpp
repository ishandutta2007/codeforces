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
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int x[maxn],y[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    int sum=1;
    int a=0,b=0;
    for(int i=1;i<=n;i++)
    {
        if(x[i]==a&&y[i]==b)
            continue;
        if(a<b)
        {
            if(x[i]>=b)
            {
                sum+=min(x[i],y[i])-b+1;
            }
        }
        else if(a>b)
        {
            if(y[i]>=a)
            {
                sum+=min(x[i],y[i])-a+1;
            }
        }
        else
        {
            sum+=min(x[i],y[i])-a;
        }
        a=x[i];
        b=y[i];
    }
    cout<<sum<<endl;
    
    
    return 0;
}