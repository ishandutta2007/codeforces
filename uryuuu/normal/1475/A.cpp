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
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;
//typedef pair<pii,int> piii;



int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        while(x%2ll==0)
        {
            x/=2ll;
        }
        if(x>1ll)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}