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
const int maxn=300005;
const ll Mod=1e9+7;

ll a[500005];


int main()
{
    sync;
    for(int i=1;i<=500000;i++)
    {
        a[i]=a[i-1]+i;
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll aa,bb;
        cin>>aa>>bb;
        if(aa>bb)
        {
            swap(aa,bb);
        }
        ll s=bb-aa;
        int pos=lower_bound(a,a+500000,s)-a;
        while(a[pos]%2!=s%2)
        {
            pos++;
        }
        cout<<pos<<endl;
    }
    return 0;
}