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
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;



int a[maxn];
int p[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    p[1]=1;
    for(int i=1;i<=n;i++)
        a[i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=i+i;j<=n;j+=i)
        {
            p[j]=1;
            a[j]=i;
        }
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    
    
    return 0;
}