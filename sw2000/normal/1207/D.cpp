#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn=3e5+10;

struct P
{
    int a,b;
}p[maxn];
ll jie[maxn];
int bu1[maxn],bu2[maxn];

bool cmp(P a,P b)
{
    if(a.a!=b.a)return a.a<b.a;
    return a.b<b.b;
}

int main()
{
    jie[0]=1;
    jie[1]=1;
    for(int i=2;i<maxn;i++)jie[i]=(jie[i-1]*i)%mod;
	int n;
	scanf("%d",&n);
	ll ans=jie[n],sub1=1,sub2=1,add=1;

	for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].a,&p[i].b);
        bu1[p[i].a]++;
        bu2[p[i].b]++;
    }
    sort(p,p+n,cmp);

    for(int i=0;i<=n;i++)
    {
        sub1*=jie[bu1[i]];
        sub1%=mod;
        sub2*=jie[bu2[i]];
        sub2%=mod;
    }

    for(int i=0;i<n-1;i++)
        if(p[i].b>p[i+1].b)
            add=0;

    if(add)
    {
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(p[i].a==p[i-1].a&&p[i].b==p[i-1].b)
            {
                cnt++;
            }
            else
            {
                add*=jie[cnt];
                add%=mod;
                cnt=1;
            }
        }
        add*=jie[cnt];
        add%=mod;
    }

    ans-=sub1+sub2;
    ans+=add;
    ans+=mod*2;
    ans%=mod;
    printf("%lld",ans);
	return 0;
}