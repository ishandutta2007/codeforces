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

struct node
{
    ll x,y;
}a[maxn];
ll b[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    if(n%2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    int d=n/2;
    ll x1,x2,y1,y2;
    for(int i=0;i<n/2;i++)
    {
        x1=a[i+1].x-a[i].x;
        x2=a[(i+d)%n].x-a[(i+1+d)%n].x;
        y1=a[i+1].y-a[i].y;
        y2=a[(i+d)%n].y-a[(i+1+d)%n].y;
        if(x1!=x2||y1!=y2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}