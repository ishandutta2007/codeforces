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
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=200010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

string s;
int nxt[1000][2];
int a[1000];

int main()
{
    sync;
    int t,n,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        cin>>s;
        for(int i=1;i<=n;i++)
        {
            a[i]=int(s[i-1]-'0');
        }
        int L,R;
        while(q--)
        {
            cin>>L>>R;
            int f=0;
            for(int i=1;i<L;i++)
            {
                if(a[i]==a[L])
                    f=1;
            }
            for(int i=R+1;i<=n;i++)
            {
                if(a[i]==a[R])
                    f=1;
            }
            if(f)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}