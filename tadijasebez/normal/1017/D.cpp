#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long int
#define pb push_back
#define mp make_pair
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
const int M=500050*15;
int w[15],suf[15];
ll sum[15];
char s[15],t[15];
int go[M][2],sz[M],tsz,root;
void Set(int &c, int len, int n)
{
	if(!c) c=++tsz;
	sz[c]++;
	if(len>n) return;
	Set(go[c][s[len]-'0'],len+1,n);
}
int Get(int &c, int len, int n, int sum, int k)
{
	if(!c) return 0;
	if(len>n) return sz[c];
	//printf("%i %i\n",c,sum);
	int g=t[len]-'0';
	if(sum+suf[len]<=k) return sz[c];
	if(sum+w[len]>k) return Get(go[c][g^1],len+1,n,sum,k);
	else return Get(go[c][g],len+1,n,sum+w[len],k)+Get(go[c][g^1],len+1,n,sum,k);
}
int main()
{
	int n,i,q,m,j,k;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=n;i++) scanf("%i",&w[i]);
	for(i=n;i>=1;i--) suf[i]=suf[i+1]+w[i];
	for(i=1;i<=m;i++)
	{
		scanf("%s",s+1);
		Set(root,1,n);
		//for(j=1;j<=n;j++) if(s[j]=='1') sum[j]+=w[j];
	}
	for(i=1;i<=q;i++)
	{
		scanf("%s %i",t+1,&k);
		//ll ans=0;
		//for(j=1;j<=n;j++) if(t[j]=='1') ans+=sum[j];
		printf("%i\n",Get(root,1,n,0,k));
	}
	return 0;
}