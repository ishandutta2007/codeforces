#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<queue>
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
#define lb(x) (x&(-x));
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

struct node
{
    int sa,ea,sb,eb;
}p[maxn],q1[maxn],q2[maxn];
int c1[maxn],c2[maxn],q[maxn],t,n;
void add(int c[],int i)
{
    while(i)
    {
        c[i]++;
        i-=lb(i);
    }
}

int query(int c[],int i)
{
    int ans=0;
    while(i<=t)
    {
        ans+=c[i];
        i+=lb(i);
    }
    return ans;
}

bool cmp1(node a,node b)
{
    return a.sa<b.sa;
}
bool cmp2(node a,node b)
{
    return a.ea<b.ea;
}

int check()
{
    t=0;
    for(int i=1;i<=n;i++)
    {
        q[++t]=p[i].sb;
        q[++t]=p[i].eb;
    }
    sort(q+1,q+t+1);
    t=unique(q+1,q+t+1)-q-1;
    for(int i=1;i<=n;i++)
    {
        p[i].sb=lower_bound(q+1,q+t+1,p[i].sb)-q;
        p[i].eb=lower_bound(q+1,q+t+1,p[i].eb)-q;
        q1[i]=q2[i]=p[i];
    }
    sort(q1+1,q1+n+1,cmp1);
    sort(q2+1,q2+n+1,cmp2);
    for(int i=1;i<=t;i++)
        c1[i]=c2[i]=0;
    int j=n;
    for(int i=n;i>=1;i--)
    {
        while(q1[j].sa>q2[i].ea)
        {
            add(c1,q1[j].sb);
            add(c2,t-q1[j].eb+1);
            j--;
        }
        if(query(c1,q2[i].eb+1)+query(c2,t-(q2[i].sb-1)+1)!=n-j)
            return 0;
    }
    return 1;
}


int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i].sa>>p[i].ea>>p[i].sb>>p[i].eb;
    if(!check())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        swap(p[i].sa,p[i].sb);
        swap(p[i].ea,p[i].eb);
    }
    if(!check())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}