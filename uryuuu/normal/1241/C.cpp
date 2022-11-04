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
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

ll p[maxn],s[maxn],ss[maxn],fir[maxn],sd[maxn],thd[maxn],d[5];

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    sync;
    int T;
    cin>>T;
    while(T--)
    {
        ll x,a,y,b,k,n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            s[i]=0;
        }
        cin>>x>>a;
        cin>>y>>b;
        for(int i=1;i<=n;i++)
        {
            if(i%a==0)
                s[i]+=x;
            if(i%b==0)
                s[i]+=y;
            ss[i]=s[i];
        }
        cin>>k;
        k*=100ll;
        int f=0;
        sort(p+1,p+n+1,cmp);
        sort(ss+1,ss+n+1,cmp);
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=p[i]*ss[i];
            if(sum>=k)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<-1<<endl;
            continue;
        }
        int l=1,r=n;
        for(int i=1;i<=n;i++)
        {
            fir[i]=sd[i]=thd[i]=0;
        }
        fir[0]=sd[0]=thd[0]=0;
        d[0]=x;
        d[1]=y;
        d[2]=x+y;
        sort(d,d+3,cmp);
        for(int i=1;i<=n;i++)
        {
            fir[i]=fir[i-1];
            sd[i]=sd[i-1];
            thd[i]=thd[i-1];
            if(s[i]==d[0])
            {
                fir[i]++;
            }
            else if(s[i]==d[1])
            {
                sd[i]++;
            }
            else if(s[i]==d[2])
                thd[i]++;
        }
        
        int ans=99999999;
        while(l<=r)
        {
            sum=0;
            int mid=(l+r)/2;
//            cout<<mid<<endl;
            int pos=1;
            for(int i=1;i<=fir[mid];i++,pos++)
            {
                sum+=d[0]*p[i];
            }
            for(int i=1;i<=sd[mid];i++,pos++)
            {
                sum+=d[1]*p[pos];
            }
            for(int i=1;i<=thd[mid];i++,pos++)
            {
                sum+=d[2]*p[pos];
            }
            if(sum>=k)
            {
                ans=min(ans,mid);
                if(l==r)
                    break;
                r=mid;
            }
            else
            {
                if(l==r)
                    break;
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}