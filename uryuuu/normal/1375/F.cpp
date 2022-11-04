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
const int maxn=400010;
const ll Mod=1000000007;
//const ll Mod=998244353;



ll a[5];
ll b[5];

int main()
{
    sync;
    cin>>a[1]>>a[2]>>a[3];
    cout<<"First"<<endl;
    cout<<2000000000ll<<endl;
    int id;
    cin>>id;
    a[id]+=2000000000ll;
    for(int i=1;i<=3;i++)
    {
        b[i]=a[i];
    }
    sort(b+1,b+4);
    ll x=2ll*(b[3])-b[1]-b[2];
    cout<<x<<endl;
    cin>>id;
    a[id]+=x;
    for(int i=1;i<=3;i++)
    {
        b[i]=a[i];
    }
    cout<<b[2]-b[1]<<endl;
    
    return 0;
}