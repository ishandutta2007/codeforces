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
const ll Mod=998244353;

int a[2005];
int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int f=0;
        int z=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2)
                f=1;
            else
                z=1;
        }
        if(f==0)
            cout<<"NO"<<endl;
        else
        {
            if(n%2==0)
            {
                if(z)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
            else
                cout<<"YES"<<endl;
        }
    }
    return 0;
}