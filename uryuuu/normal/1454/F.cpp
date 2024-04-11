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
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn];
int b[maxn];
map<int,int>mp;
vector<int>g[maxn];
int Lmin[maxn],Rmin[maxn],Lmax[maxn],Rmax[maxn],st[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        int n;
        cin>>n;
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        
        sort(b+1,b+n+1);
        tot=unique(b+1,b+n+1)-b-1;
        for(int i=1;i<=n;i++)
        {
            a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
        }
        
        for(int i=1;i<=tot;i++)
            g[i].clear();
        for(int i=1;i<=n;i++)
        {
            g[a[i]].push_back(i);
        }
        
        int cnt;
        
        st[0]=0;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            while(cnt>0&&a[i]>=a[st[cnt]])
            {
                cnt--;
            }
            Lmax[i]=st[cnt]+1;
            st[++cnt]=i;
        }
        
        st[0]=0;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            while(cnt>0&&a[i]<=a[st[cnt]])
            {
                cnt--;
            }
            Lmin[i]=st[cnt]+1;
            st[++cnt]=i;
        }
        
        st[0]=n+1;
        cnt=0;
        for(int i=n;i>=1;i--)
        {
            while(cnt>0&&a[i]>=a[st[cnt]])
            {
                cnt--;
            }
            Rmax[i]=st[cnt]-1;
            st[++cnt]=i;
        }
        
        st[0]=n+1;
        cnt=0;
        for(int i=n;i>=1;i--)
        {
            while(cnt>0&&a[i]<=a[st[cnt]])
            {
                cnt--;
            }
            Rmin[i]=st[cnt]-1;
            st[++cnt]=i;
        }
        
//        for(int i=1;i<=n;i++)
//        {
//            cout<<Rmin[i]<<' ';
//        }
        
        int f=0;
        int L,R,sz,p,x,y,z;
        for(int i=1;i<=tot;i++)
        {
            if(g[i].size()<3)
                continue;
            sz=g[i].size();
            if(Lmax[g[i][0]]>1||Rmax[g[i][sz-1]]<n)
                continue;
            L=Rmax[g[i][0]];
            R=Lmax[g[i][sz-1]];
            for(int j=1;j<sz-1;j++)
            {
                p=g[i][j];
                if(Lmin[p]<=L+1&&Rmin[p]>=R-1)
                {
                    cout<<"YES"<<endl;
                    x=min(L,p-1);
                    y=max(R,p+1);
                    z=n-y+1;
                    y=y-x-1;
                    cout<<x<<' '<<y<<' '<<z<<endl;
                    f=1;
                    break;
                }
            }
            if(f)
                break;
        }
        if(f==0)
        {
            cout<<"NO"<<endl;
        }
        
        
    }
    
    return 0;
}