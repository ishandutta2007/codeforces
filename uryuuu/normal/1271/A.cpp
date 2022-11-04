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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll Mod=1000000007;


int main()
{
    sync;
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    ll zx=min(b,min(c,d));
    ll s=zx*f+min(a,d-zx)*e;
    ll aa=min(a,d);
    d-=aa;
    zx=min(b,min(c,d));
    s=max((aa*e+zx*f),s);
    cout<<s<<endl;
    return 0;
}