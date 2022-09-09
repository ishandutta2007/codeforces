#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int S[N],C[N],c,k,a[N];
void Add(int f)
{
	if(S[c]!=f)
	{
		S[++c]=f;
		C[c]=1;
	}
	else C[c]++;
	if(C[c]==k) c--;
}
int main()
{
	int n,m,i;
	scanf("%i %i %i",&n,&k,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Add(a[i]);
	if(c==0) return 0*printf("0\n");
	if(c==1) return 0*printf("%lld\n",(ll)C[1]*m%k);
	ll ans=0;
	for(i=1;i<=c;i++) ans+=C[i];
	ll tmp=ans;
	for(i=1;i<=c/2;i++)
	{
		if(S[i]==S[c-i+1])
		{
			if(C[i]+C[c-i+1]>=k) tmp-=k;
			if(C[i]+C[c-i+1]!=k) break;
		}
		else break;
	}
	if(!(c%2==1 && i==(c+1)/2))
	{
		ans+=tmp*(m-1);
		printf("%lld\n",ans);
	}
	else
	{
		ll ost=(ll)C[(c+1)/2]*m%k;
		if(ost==0)
		{
			c=c/2;
			int f=c;
			for(i=f+2;i<=f*2+1;i++) for(int j=1;j<=C[i];j++) Add(S[i]);
			ans=0;
			for(i=1;i<=c;i++) ans+=C[i];
			printf("%lld\n",ans);
		}
		else printf("%lld\n",ans-C[(c+1)/2]+ost);
	}
	return 0;
}