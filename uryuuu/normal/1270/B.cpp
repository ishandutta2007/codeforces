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
const int maxn=200005;
const ll Mod=1e9+7;

int a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int da=-1;
        int p;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>da)
            {
                da=a[i];
                p=i;
            }
        }
        int f=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]-a[i-1]>=2||a[i-1]-a[i]>=2)
            {
                f=1;
                cout<<"YES"<<endl;
                cout<<i-1<<' '<<i<<endl;
                break;
            }
        }
        if(f==0)
            cout<<"NO"<<endl;
    }
    return 0;
}