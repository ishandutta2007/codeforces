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
const int maxn=10005;
const ll Mod=1000000007;

ll a[maxn];

int main()
{
    int n,m;
    cin>>n>>m;
    if(m==0)
    {
        for(int i=0;i<n;i++)
            cout<<i*2+1<<' ';
        cout<<endl;
        return 0;
    }
    if(n<3)
    {
        cout<<-1<<endl;
        return 0;
    }
    int d=n-2;
    int s=(1+d/2)*d/2;
    if(d%2)
        s+=d/2+1;
    if(s<m)
    {
//        cout<<s<<' '<<m<<endl;
        cout<<-1<<endl;
        return 0;
    }
    a[1]=1;
    a[2]=2;
    s=0;
    int p=999999;
    for(int i=3;i<=n;i++)
    {
        d=(i-1)/2;
        if((s+d)>m)
        {
            a[i]=i+((s+d)-m)*2;
            p=i+1;
            break;
        }
        s+=d;
        a[i]=i;
    }
    int dd=150001;
    for(int i=p;i<=n;i++)
    {
        a[i]=dd;
        dd+=10001;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    
    return 0;
}