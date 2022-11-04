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

int a[15],b[15];

int main()
{
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=6;
    sync;
    int n;
    int t;
    for(int i=0;i<=9;i++)
    {
        a[i]-=2;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        int s=n/2;
        int sum=1;
        for(int i=0;i<s-1;i++)
        {
            sum*=10;
        }
        n-=2*s;
//        cout<<n<<' '<<s<<' '<<sum<<endl;
            for(int j=9;j>=0;j--)
            {
                if(a[j]<=n)
                {
                    cout<<j;
                    break;
                }
            }
        for(int i=1;i<s;i++)
            cout<<'1';
        cout<<endl;
    }
    return 0;
}