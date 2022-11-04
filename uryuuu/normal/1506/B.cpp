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
//#include <chrono>
//#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;


string s;

int a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cin>>s;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                a[++cnt]=i;
            }
        }
        if(cnt<=2)
        {
            cout<<cnt<<endl;
            continue;
        }
        int sum=2;
        int pos,x;
        int L=1;
        while(L<cnt)
        {
            x=a[L];
            pos=lower_bound(a+1,a+cnt+1,x+k+1)-a-1;
            if(pos==cnt)
                break;
            sum++;
            L=pos;
        }
        cout<<sum<<endl;
        
    }
    return 0;
}