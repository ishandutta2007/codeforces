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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

struct node
{
    ll x;
    int id;
}a[maxn];

bool cmp(node a,node b)
{
    return a.x<b.x;
}

int f=0;
int n;

int check(ll d)
{
    for(int i=1;i<n;i++)
    {
        if(a[i].x+d!=a[i+1].x)
        {
            if(f==0)
            {
                if(i+2==n+1||a[i].x+d==a[i+2].x)
                {
                    f=a[i+1].id;
                    i++;
                }
                else if(a[i+2].x-a[i+1].x==d)
                {
                    if(i==1||a[i+1].x-a[i-1].x==d)
                    {
                        f=a[i].id;
                    }
                    else
                        return 0;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
    if(f==0)
        f=a[n].id;
    return 1;
}



int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x;
        a[i].id=i;
    }
    if(n<=3)
    {
        cout<<1<<endl;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    ll q=a[n].x-a[n-1].x,w=a[2].x-a[1].x;
    f=0;
    if(check(q))
    {
        cout<<f<<endl;
        return 0;
    }
    f=0;
    if(check(w))
    {
        cout<<f<<endl;
        return 0;
    }
    cout<<-1<<endl;
    
    return 0;
}