#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<queue>
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
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;


int n;


ll s[10];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,x,y;
        cin>>a>>b>>x>>y;
        x++;
        y++;
        s[0]=(x-1)*b;
        s[1]=(a-x)*b;
        s[2]=a*(y-1);
        s[3]=a*(b-y);
        sort(s,s+4);
        cout<<s[3]<<endl;
    }
    return 0;
}