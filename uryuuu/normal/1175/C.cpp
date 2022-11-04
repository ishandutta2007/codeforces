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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;


ll a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        k++;
        rep(i,1,n)
        cin>>a[i];
        ll zd=2e15;
        int l=1,r=k;
        ll L=a[l],R=a[r];
        while(r<=n)
        {
            if(zd>1ll*(a[r]-a[l]))
            {
                zd=1ll*(a[r]-a[l]);
                L=a[l];
                R=a[r];
            }
            l++;
            r++;
        }
        cout<<1ll*(L+R)/2<<endl;
    }
    
    return 0;
}