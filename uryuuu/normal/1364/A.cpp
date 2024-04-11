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
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn];
int s;
int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>n>>x;
        s=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]%=x;
            s+=a[i];
        }
        int l=0,r=0;
        if(s%x!=0)
        {
            cout<<n<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
                l++;
            else
                break;
        }
        for(int i=n;i>=1;i--)
        {
            if(a[i]==0)
                r++;
            else
                break;
        }
        
        if(l==n)
        {
            cout<<-1<<endl;
            continue;
        }
        
        cout<<n-min(l,r)-1<<endl;
        
    }
    
    
    return 0;
}