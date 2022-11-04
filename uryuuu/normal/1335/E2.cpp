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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn];
int s[205][maxn];
vector<int>g[205];
int R[205];
int L[205];

int main()
{
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=205;i++)
        {
            R[i]=0;
            L[i]=0;
            g[i].clear();
        }
        scanf("%d",&n);
        for(int i=1;i<=200;i++)
        {
            for(int j=1;j<=n;j++)
            {
                s[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ++R[a[i]];
            g[a[i]].push_back(i);
            s[a[i]][i]++;
        }
        for(int i=1;i<=200;i++)
        {
            for(int j=1;j<=n;j++)
            {
                s[i][j]=s[i][j]+s[i][j-1];
            }
        }
        int d;
        int r;
        int sz;
        int ans=0;
        for(int i=1;i<=200;i++)
        {
            ans=max(ans,R[i]);
        }
        for(int i=1;i<=n;i++)
        {
            d=a[i];
            sz=R[a[i]];
            L[d]++;
            if(L[d]*2>sz)
                continue;
            r=g[d][sz-L[d]]-1;
            if(r-i+L[d]*2<ans)
                continue;
            int zd=0;
            for(int j=1;j<=200;j++)
            {
                zd=max(s[j][r]-s[j][i],zd);
            }
            ans=max(zd+L[d]*2,ans);
        }
        printf("%d\n",ans);
//        cout<<"fuck"<<endl;
        
    }
    
    return 0;
}