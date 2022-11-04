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
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;


int a[maxn],aa[maxn],c[maxn],cc[maxn];

string s,sa,sc;
int main()
{
    sync;
    int n;
    cin>>n;
    cin>>s;
    int pos=n/2;
    int b=pos+1;
    int p=n;
    while(b<n)
    {
        if(s[b]!='0')
        {
            p=b;
            break;
        }
        b++;
    }
    
    b=pos;
    int pp=n-1;
    while(b>0)
    {
        if(s[b]!='0')
        {
            pp=b;
            break;
        }
        b--;
    }
    pos=0;
    for(int i=n-1;i>=p;i--)
    {
        a[pos++]=ch(s[i]);
    }
    pos=0;
    for(int i=p-1;i>=0;i--)
    {
        aa[pos++]=ch(s[i]);
    }
    int lena=max(n-p,p);
    int w=0,sum=0;
    for(int i=0;i<lena;i++)
    {
        sum=a[i]+aa[i]+w;
        sa+=char('0'+sum%10);
        w=sum/10;
    }
    if(w>0)
    {
        sa+=char('0'+w);
        lena++;
    }
    reverse(sa.begin(),sa.end());
    
    pos=0;
//    cout<<pp<<endl;
    for(int i=n-1;i>=pp;i--)
    {
        c[pos++]=ch(s[i]);
    }
    pos=0;
    for(int i=pp-1;i>=0;i--)
    {
        cc[pos++]=ch(s[i]);
    }
    int lenc=max(n-pp,pp);
    w=0;
    sum=0;
    for(int i=0;i<lenc;i++)
    {
        sum=c[i]+cc[i]+w;
        sc+=char('0'+sum%10);
        w=sum/10;
    }
//    cout<<sc<<endl;
    if(w>0)
    {
        sc+=char('0'+w);
        lenc++;
    }
    reverse(sc.begin(),sc.end());
    
//    cout<<sa<<' '<<sc<<endl;
    if(lena>lenc)
    {
        cout<<sc<<endl;
    }
    else if(lena<lenc)
    {
        cout<<sa<<endl;
    }
    else
    {
        if(sa<sc)
            cout<<sa<<endl;
        else
            cout<<sc<<endl;
    }
    return 0;
}