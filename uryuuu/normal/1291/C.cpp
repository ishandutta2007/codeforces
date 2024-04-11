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
const int maxn=4005;
const ll Mod=1e9+7;


int a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    int n,m,k;
    while(t--)
    {
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int zd=0;
        int d=min(k,m-1);
        for(int i=0;i<=d;i++)
        {
            int l=1+i,r=n-(d-i);
            int zx=1e9+2;
            for(int j=0;j<=m-1-d;j++)
            {
                int L=l+j,R=r-(m-1-d-j);
//                cout<<L<<' '<<R<<endl;
                zx=min(max(a[L],a[R]),zx);
            }
            zd=max(zd,zx);
        }
        cout<<zd<<endl;
//        cout<<endl;
    }
    return 0;
}