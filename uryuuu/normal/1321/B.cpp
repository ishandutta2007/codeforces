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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;


ll a[maxn];
ll b[2000005];

int main()
{
    sync;
    int n;
    cin>>n;
    int id;
    ll zd=0ll;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        id=a[i]-i+1000000;
        b[id]+=1ll*a[i];
        zd=max(zd,b[id]);
    }
    cout<<zd<<endl;
    return 0;
}