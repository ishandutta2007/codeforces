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

struct node
{
    int t,l,r;
}a[205];

int main()
{
    sync;
    int T,n,m;
    cin>>T;
    int d,L,R;
    while(T--)
    {
        int f=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i].t>>a[i].l>>a[i].r;
        for(int i=n-1;i>=1;i--)
        {
            d=a[i+1].t-a[i].t;
            L=a[i+1].l-d;
            R=a[i+1].r+d;
            if(a[i].l>R||a[i].r<L)
            {
                f=1;
                break;
            }
            a[i].l=max(a[i].l,L);
            a[i].r=min(a[i].r,R);
        }
        L=m-a[1].t;
        R=m+a[1].t;
        if(a[1].r<L||a[1].l>R)
            f=1;
        if(f)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}