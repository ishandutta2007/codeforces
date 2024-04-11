#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define maxn 1000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int p[maxn+5],k[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    int tot=0;
    for(int i=2;1ll*i*i<=n;i++)
    {
        if(n%i==0)
        {
            p[++tot]=i;
            while(n%i==0)
            {
                k[tot]++;
                n/=i;
            }
        }
    }
    if(n>1) p[++tot]=n,k[tot]++;
    int x=0,cnt=0,f=0;
    rep(i,1,tot) x=max(x,k[i]);
    if(x==0)
    {
        printf("1 0\n");
        return 0;
    }
    int pw;
    for(pw=1;pw<x;pw<<=1) cnt++;
    rep(i,1,tot) if(k[i]!=pw) f=1;
    cnt+=f;
    int ans=1;
    rep(i,1,tot) ans*=p[i];
    printf("%d %d\n",ans,cnt);
    return 0;
}