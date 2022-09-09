#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
char s[N];
int n,k;
int sum[N];
bool Check1(int l, int r)
{
	int tmp=sum[l-1]+sum[n]-sum[r];
	if(tmp==0 || tmp==n-k) return 1;
	return 0;
}
int nxt[N][2],pre[N][2],fir[2],las[2];
bool Check20(int l, int r)
{
	if(!nxt[r][0] && !pre[l][0]) return 1;
	int R=las[1];
	if(!R || R<=r) R=pre[l][1];
	int L=fir[1];
	if(!L || L>=l) L=nxt[r][1];
	if(R-L+1<=k) return 1;
	return 0;
}
bool Check21(int l, int r)
{
	if(!nxt[r][1] && !pre[l][1]) return 1;
	int R=las[0];
	if(!R || R<=r) R=pre[l][0];
	int L=fir[0];
	if(!L || L>=l) L=nxt[r][0];
	if(R-L+1<=k) return 1;
	return 0;
}
bool Check2(int l, int r)
{
	return Check20(l,r) && Check21(l,r);
}
int main()
{
	scanf("%i %i",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='1');
	for(int i=1;i<=n;i++)
	{
		pre[i][0]=las[0];
		pre[i][1]=las[1];
		las[s[i]-'0']=i;
	}
	for(int i=n;i>=1;i--)
	{
		nxt[i][0]=fir[0];
		nxt[i][1]=fir[1];
		fir[s[i]-'0']=i;
	}
	for(int i=1;i<=n-k+1;i++)
	{
		if(Check1(i,i+k-1))
		{
			printf("tokitsukaze\n");
			return 0;
		}
	}
	int cnt=0;
	for(int i=1;i<=n-k+1;i++)
	{
		if(Check2(i,i+k-1)) cnt++;
	}
	if(cnt==n-k+1) printf("quailty\n");
	else printf("once again\n");
	return 0;
}