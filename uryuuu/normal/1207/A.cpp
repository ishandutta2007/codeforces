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
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1000005;
const ll Mod=1000000007;

int main()
{
    sync;
    int t,b,p,f,h,c;
    cin>>t;
    while(t--)
    {
        cin>>b>>p>>f>>h>>c;
        int da=0;
        if(c>h)
        {
            int z=min(b/2,f);
            da+=z*c;
            b-=2*z;
            z=min(b/2,p);
            da+=z*h;
        }
        else
        {
            int z=min(b/2,p);
            da+=z*h;
            b-=2*z;
            z=min(b/2,f);
            da+=z*c;
        }
        cout<<da<<endl;
    }
    return 0;
}