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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;


vector<int>g[maxn];
int a[maxn];
int c[maxn];
int siz[maxn];
bool cmp(int a,int b)
{
    return a>b;
}


int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    rep(i,1,n)
    cin>>a[i];
    rep(i,1,k)
    cin>>c[i];
    sort(a+1,a+n+1,cmp);
    int pos=1;
    int x;
    int cnt;
    int y;
    int m=1;
    while(pos<=n)
    {
        x=a[pos];
        y=c[x];
        cnt=m;
        int L=1,R=m;
        while(L<R)
        {
            int mid=(L+R)/2;
            if(siz[mid]<y)
            {
                R=mid;
                cnt=min(cnt,mid);
            }
            else
            {
                L=mid+1;
            }
        }
        while(a[pos]==x&&pos<=n)
        {
            if(siz[cnt]<y)
            {
                g[cnt].push_back(x);
                pos++;
                siz[cnt]++;
            }
            else
                cnt++;
        }
        m=max(m,cnt);
    }
    cout<<m<<endl;
    for(int i=1;i<=m;i++)
    {
        cout<<siz[i]<<' ';
        for(int j=0;j<siz[i];j++)
            cout<<g[i][j]<<' ';
        cout<<endl;
    }
    
    return 0;
}