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
const int maxn=300005;
const ll Mod=1000000007;

int a[maxn],b[maxn],L[maxn],R[maxn];

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            L[i]=n+1000000;
            R[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
            L[a[i]]=min(i,L[a[i]]);
            R[a[i]]=i;
        }
        sort(b+1,b+n+1);
        int cnt=unique(b+1,b+n+1)-b-1;
        int zd=1;
        int l=L[b[1]],r=R[b[1]];
        int len=1;
        for(int i=2;i<=cnt;i++)
        {
            zd=max(len,zd);
            if(L[b[i]]<r)
            {
                len=1;
                l=L[b[i]];
                r=R[b[i]];
            }
            else
            {
                len++;
                r=r=R[b[i]];
            }
            zd=max(len,zd);
        }
        cout<<cnt-zd<<endl;
    }
    
    return 0;
}