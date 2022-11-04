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
//#include<unordered_map>
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
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;
//typedef pair<pii,int> piii;

ll c1[maxn],c2[maxn];
struct node
{
    ll a,b;
}s[maxn];

bool cmp(ll a,ll b)
{
    return a>b;
}
ll pre[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll m;
        cin>>n>>m;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i].a;
            sum+=s[i].a;
        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i].b;
            if(s[i].b==1)
            {
                c1[++cnt1]=s[i].a;
            }
            else
            {
                c2[++cnt2]=s[i].a;
            }
            
        }
        if(sum<m)
        {
            cout<<-1<<endl;
            continue;
        }
        
        pre[0]=0ll;
        sort(c1+1,c1+cnt1+1,cmp);
        sort(c2+1,c2+cnt2+1,cmp);
        for(int i=1;i<=cnt1;i++)
        {
            pre[i]=pre[i-1]+c1[i];
        }
        
        int ans=lower_bound(pre+1,pre+cnt1+1,m)-pre;
        if(ans==cnt1+1)
            ans=2e8;
        
        
        int pos;
        sum=0ll;
        for(int i=1;i<=cnt2;i++)
        {
            sum+=c2[i];
            if(sum>=m)
            {
                ans=min(ans,2*i);
            }
            pos=lower_bound(pre+1,pre+cnt1+1,1ll*m-sum)-pre;
            if(pos!=cnt1+1)
            {
                ans=min(ans,i*2+pos);
            }
        }
        cout<<ans<<endl;
        
    }
    
    return 0;
}