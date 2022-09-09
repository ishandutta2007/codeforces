#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define mp make_pair
#define ll long long
const int mod=1e9+7;
const int N=300050;
char s[N];
pair<pair<int,int> ,int> tmp[N];
int sa[N],id[N],lcp[N],tot,t[N];
void BuildSuffixArray()
{
	int i,j;
	for(i=1;i<=tot;i++) id[i]=s[i]-'a';
	for(j=0;j<20;j++)
	{
		for(i=1;i<=tot;i++) tmp[i]=mp(mp(id[i],i+(1<<j)<=tot?id[i+(1<<j)]:0),i);
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
	int i,j,k=0;
	for(i=1;i<=tot;i++)
	{
		if(id[i]==tot) continue;
		else
		{
			j=sa[id[i]+1];
			while(i+k<=tot && j+k<=tot && s[i+k]==s[j+k]) k++;
			lcp[id[i]]=k;
			if(k) k--;
		}
	}
}
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int sum[4][N],S[N],c,l[N],r[N],sol[N];
int main()
{
	int i,j,p=1,sz=N;
	scanf("%s",s+1);sz=min(sz,strlen(s+1));
	tot+=strlen(s+1);
	for(i=p;i<=tot;i++) t[i]=1;
	s[++tot]='a'+26;
	p=tot+1;
	scanf("%s",s+tot+1);sz=min(sz,strlen(s+1+tot));
	tot+=strlen(s+tot+1);
	for(i=p;i<=tot;i++) t[i]=2;
	s[++tot]='a'+27;
	p=tot+1;
	scanf("%s",s+tot+1);sz=min(sz,strlen(s+1+tot));
	tot+=strlen(s+tot+1);
	for(i=p;i<=tot;i++) t[i]=3;
	s[++tot]='a'+28;
	//printf("%s %i\n",s+1,sz);
	BuildSuffixArray();
	BuildLCPArray();
	//for(i=1;i<=tot;i++) printf("%i ",sa[i]);printf("\n");
	//for(i=1;i<=tot;i++) printf("%i ",lcp[i]);printf("\n");
	for(i=1;i<=tot;i++) sum[t[sa[i]]][i]++;
	for(i=1;i<=tot;i++) for(j=1;j<=3;j++) sum[j][i]+=sum[j][i-1];
	for(i=1;i<tot;i++)
	{
		while(c && lcp[S[c]]>lcp[i]) r[S[c]]=i,c--;
		//while(c && lcp[S[c]]==lcp[i]) r[S[c]]=l[S[c]]-1,c--;
		if(c) l[i]=S[c]+1;
		else l[i]=1;
		S[++c]=i;
	}
	while(c) r[S[c]]=tot,c--;
	for(i=1;i<tot;i++)
	{
		int a=sum[1][r[i]]-sum[1][l[i]-1],b=sum[2][r[i]]-sum[2][l[i]-1],c=sum[3][r[i]]-sum[3][l[i]-1];
		//printf("%i (%i %i) %i %i %i\n",lcp[i],l[i],r[i],a,b,c);
		int add=(ll)a*b%mod*c%mod;
		int h=max(lcp[r[i]],lcp[l[i]-1]);
		sol[h+1]+=add;if(sol[h+1]>=mod) sol[h+1]-=mod;
		sol[lcp[i]+1]+=mod-add;if(sol[lcp[i]+1]>=mod) sol[lcp[i]+1]-=mod;
		//sol[lcp[i]]+=(ll)a*b%mod*c%mod;
		//if(sol[lcp[i]]>=mod) sol[lcp[i]]-=mod;
	}
	//for(i=sz;i>=1;i--)
	//{
		//sol[i]+=sol[i+1];
		//if(sol[i]>=mod) sol[i]-=mod;
	//}
	for(i=1;i<=sz;i++) sol[i]+=sol[i-1],sol[i]=sol[i]>=mod?sol[i]-mod:sol[i];
	for(i=1;i<=sz;i++) printf("%i ",sol[i]);printf("\n");
	return 0;
}