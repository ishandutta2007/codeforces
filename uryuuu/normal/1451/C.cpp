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
const int maxn=2000010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

string a,b;
int visa[30],visb[30];

int main()
{
    sync;
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>a>>b;
        mm(visa);
        mm(visb);
        for(int i=0;i<n;i++)
        {
            visa[ch(a[i])]++;
            visb[ch(b[i])]++;
        }
        int f=0;
        for(int i=1;i<=26;i++)
        {
            if(visa[i]>=visb[i]&&(visa[i]-visb[i])%k==0)
            {
                visa[i+1]+=(visa[i]-visb[i]);
            }
            else
            {
                f=1;
                break;
            }
        }
        if(f)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    
    return 0;
}