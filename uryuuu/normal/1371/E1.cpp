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
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll a[maxn];
int b[maxn];
map<ll,int>mp;

int main()
{
    sync;
    int n,p;
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        mp[a[i]]=i;
    }
    int cnt=0;
    ll s;
    for(int i=1;i<=2005;i++)
    {
        int f=0;
        for(int j=1;j<=n;j++)
        {
            s=a[j]-i;
//            cout<<s<<' '<<j<<endl;
            if((j-max(s,0ll))%p==0||s>=j)
            {
                f=1;
                break;
            }
        }
//        cout<<endl;
//        cout<<endl<<i<<endl<<endl;
        if(f==0)
        {
            b[cnt++]=i;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        cout<<b[i]<<' ';
    }
    cout<<endl;
    return 0;
}