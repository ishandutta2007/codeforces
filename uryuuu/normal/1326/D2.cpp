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
const double pi=acos(-1);
const int maxn=2000050;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

char s[maxn];
char b[maxn],a[maxn];
int cnt;
int p[maxn];

void mlc()
{
    int mx=0,id=0;
    int m=0;
    int ans=0;
    a[++m]='$';
    a[++m]='#';
    p[0]=p[1]=p[2]=1;
    for(int i=1;i<=cnt;i++)
    {
        a[++m]=b[i];
        p[m]=1;
        a[++m]='#';
        p[m]=1;
    }
    int zd=1,pos=3;
    a[++m]='%';
    for(int i=3;i<m;i++)
    {
        p[i]=1;
        if(id+p[id]>i)
            p[i]=min(id+p[id]-i,p[2*id-i]);
        while(a[i+p[i]]==a[i-p[i]])
            p[i]++;
        if(p[i]+i>mx)
        {
            mx=p[i]+i;
            id=i;
        }
        if(p[i]+i-1>=2*cnt+1||i-p[i]+1<=3)
            if(p[i]>zd)
            {
                zd=p[i];
                pos=i;
            }
    }
    for(int i=pos-zd+1;i<=pos+zd-1;i++)
    {
        if(a[i]<='z'&&a[i]>='a')
            cout<<a[i];
    }
}


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s+1;
        int n=strlen(s+1);
//        cout<<n<<endl;
        int l=0;
        while(l+1<=n/2)
        {
            if(s[l+1]==s[n-l])
                l++;
            else
            {
                break;
            }
        }
        for(int i=1;i<=l;i++)
            cout<<s[i];
        cnt=0;
        for(int i=l+1;i<=(n-l);i++)
        {
            b[++cnt]=s[i];
        }
        mlc();
        for(int i=l;i>=1;i--)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}