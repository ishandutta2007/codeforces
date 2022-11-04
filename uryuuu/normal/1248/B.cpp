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

ll a[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>n;
    ll b=0,c=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int l=0,r=n-1;
    while(l<=r)
    {
        b+=a[r--];
        if(l>r)
            break;
        c+=a[l++];
    }
//    cout<<b<<' '<<c<<endl;
    cout<<b*b+c*c<<endl;
    return 0;
}