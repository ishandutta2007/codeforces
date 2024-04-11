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
typedef pair<int,int> pii;
const int maxn=100005;
const ll Mod=1000000007;

int a[maxn];

int main()
{
    sync;
    int t,n,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        int zx=1e9+10;
        int d;
        int s;
        for(int i=1;i<=n;i++)
        {
            cin>>d;
            s=x/d;
            if(x%d)
                s=max(2,s+1);
            zx=min(zx,s);
        }
        cout<<zx<<endl;
    }
    
    return 0;
}