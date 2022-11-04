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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;
//typedef pair<pii,int> piii;


struct node
{
    ll w,id;
}a[maxn];

bool cmp(node a,node b)
{
    return a.w<b.w;
}

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    ll R,L;
    while(t--)
    {
        cin>>n>>R;
        L=(R+1ll)/2ll;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].w;
            a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        
        int f=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].w>=L&&a[i].w<=R)
            {
                cout<<1<<endl;
                cout<<a[i].id<<endl;
                f=1;
                break;
            }
        }
        if(f)
            continue;
        
        ll sum=0,pos=n;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i].w;
            if(sum>=L)
            {
                pos=i;
                break;
            }
        }
        if(sum<L||sum>R)
        {
            cout<<-1<<endl;
            continue;
        }
    
        cout<<pos<<endl;
        for(int i=1;i<=pos;i++)
            cout<<a[i].id<<' ';
        cout<<endl;
        
    }
    
    
    return 0;
}