#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define mp make_pair
int max(int a, int b){ return a>b?a:b;}
const int N=200050;
const int M=2*N;
char s[N];
int tot,sa[N],id[M],lcp[N];
bool b[N];
pair<pair<int,int> ,int> tmp[N];
void Add(char c, bool ban){ s[++tot]=c;b[tot]=ban;}
void BuildSuffixArray()
{
	s[++tot]='a'+26;b[tot]=1;
	int i,j;
	for(i=1;i<=tot;i++) id[i]=s[i]-'a';
	for(j=0;j<20;j++)
	{
		for(i=1;i<=tot;i++) tmp[i]=mp(mp(id[i],id[i+(1<<j)]),i);
		sort(tmp+1,tmp+1+tot);
		int c=0;
		for(i=1;i<=tot;i++)
		{
			id[tmp[i].second]=c+1;
			c+=tmp[i].first!=tmp[i+1].first;
		}
		if(c==tot) break;
	}
	for(i=1;i<=tot;i++) sa[id[i]]=i;
}
void BuildLCPArray()
{
	int i,k=0,j;
	for(i=1;i<=tot;i++)
	{
		if(id[i]==tot) continue;
		else
		{
			j=sa[id[i]+1];
			while(k+j<=tot && k+i<=tot && s[k+j]==s[k+i]) k++;
			lcp[id[i]]=k;
			if(k) k--;
		}
	}
}
char t[N],bn[N];
int sum[N];
int Get(int l, int r){ return sum[r]-sum[l-1];}
int l[N],r[N],S[N],c;
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",t+1);
	scanf("%s",bn+1);
	for(i=n;i>=1;i--) Add(t[i],bn[i]=='1');
	BuildSuffixArray();
	BuildLCPArray();
	for(i=1;i<=tot;i++){ if(!b[sa[i]]) sum[i]++;sum[i]+=sum[i-1];}
	ll sol=0;
	for(i=1;i<=tot;i++)
	{
		while(c && lcp[i]<=lcp[S[c]])
		{
			r[S[c]]=i;
			c--;
		}
		l[i]=S[c]+1;
		S[++c]=i;
	}
	while(c) r[S[c]]=tot,c--;
	for(i=1;i<=tot;i++)
	{
		sol=max(sol,(ll)lcp[i]*Get(l[i],r[i]));
		sol=max(sol,(ll)(tot-sa[i])*Get(i,i));
	}
	//for(i=1;i<=tot;i++) printf("%i ",sa[i]);printf("\n");
	//for(i=1;i<=tot;i++) printf("%i ",lcp[i]);printf("\n");
	printf("%lld\n",sol);
	return 0;
}