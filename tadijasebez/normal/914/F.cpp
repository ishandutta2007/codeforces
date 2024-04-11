#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
const int N=100050;
const int S=150;
const int M=S*2+69;
struct SuffixAutomaton
{
	int go[M][26],len[M],link[M],dp[M],term[M];
	SuffixAutomaton(){}
	Calc(int u)
	{
		if(dp[u]!=-1) return dp[u];
		dp[u]=term[u];
		for(int i=0;i<26;i++) dp[u]+=Calc(go[u][i]);
		return dp[u];
	}
	int Solve(string &s)
	{
		int cur=1,i;
		for(i=0;i<s.size();i++) cur=go[cur][s[i]-'a'];
		return Calc(cur);
	}
} Block[M*3];
void Build(SuffixAutomaton &a, string &s)
{
	int sz=1,last=1,i,j;
	a.len[1]=0;
	a.link[1]=0;
	for(j=0;j<26;j++) a.go[1][j]=0;
	for(i=0;i<s.size();i++)
	{
		int nod=++sz;
		for(j=0;j<26;j++) a.go[nod][j]=0;
		a.len[nod]=i+1;
		a.link[nod]=1;
		int cur=last;
		while(cur && !a.go[cur][s[i]-'a']) a.go[cur][s[i]-'a']=nod,cur=a.link[cur];
		if(cur)
		{
			int cld=a.go[cur][s[i]-'a'];
			if(a.len[cld]==a.len[cur]+1) a.link[nod]=cld;
			else
			{
				int tmp=++sz;
				for(j=0;j<26;j++) a.go[tmp][j]=a.go[cld][j];
				a.len[tmp]=a.len[cur]+1;
				a.link[tmp]=a.link[cld];
				a.link[cld]=tmp;
				a.link[nod]=tmp;
				while(cur && a.go[cur][s[i]-'a']==cld) a.go[cur][s[i]-'a']=tmp,cur=a.link[cur];
			}
		}
		last=nod;
	}
	for(i=1;i<=sz;i++) a.dp[i]=-1,a.term[i]=0;
	while(last) a.term[last]=1,last=a.link[last];
}
char word[N];
string str;
int z[N*2];
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int BruteForce(int l, int r)
{
	string tmp=str;
	tmp+='$';
	int i;
	for(i=l;i<=r;i++) tmp+=word[i];
	int L=0,R=0;
	z[0]=0;
	for(i=1;i<tmp.size();i++)
	{
		z[i]=0;
		if(i<R) z[i]=min(z[i-l],r-i+1);
		while(tmp[i+z[i]]==tmp[z[i]]) z[i]++;
		if(z[i]+i-1>r) r=z[i]+i-1,l=i;
	}
	int ans=0;
	for(i=0;i<tmp.size();i++) ans+=(z[i]==str.size());
	return ans;
}
int main()
{
	int n,q,i,j,t,p,l,r;
	char ch,taj;
	scanf("%s",word+1);
	n=strlen(word+1);
	bool Only=1;taj=word[1];
	for(i=1;i<=n;i++) if(word[i]!=taj) Only=0;
	string tmp;
	for(i=0;i<=n;i+=S)
	{
		tmp="";
		for(j=max(1,i);j<min(n+1,i+S);j++) tmp+=word[j];
		Build(Block[i/S],tmp);
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %c",&p,&ch);
			if(Only) if(ch!=taj) Only=0;
			word[p]=ch;
			int B=p/S;
			tmp="";
			for(i=max(1,B*S);i<min(n+1,(B+1)*S);i++) tmp+=word[i];
			Build(Block[B],tmp);
		}
		else
		{
			scanf("%i %i",&l,&r);
			cin >> str;
			if(Only)
			{
				bool ok=1;
				for(i=0;i<str.size();i++) if(str[i]!=str[0]) ok=0;
				if(!ok || str[0]!=taj || r-l+1<str.size()) printf("0\n");
				else printf("%i\n",r-l+1-str.size()+1);
				continue;
			}
			int sz=str.size(),L=l/S,R=r/S;
			if(sz>S || L==R) printf("%i\n",BruteForce(l,r));
			else
			{
				int ans=0;
				ans+=BruteForce(l,(L+1)*S-1);
				for(i=L+1;i<R;i++) ans+=Block[i].Solve(str);
				ans+=BruteForce(R*S,r);
				for(i=L+1;i<=R;i++) ans+=BruteForce(max(l,i*S-sz+1),min(r,i*S+sz-2));
				printf("%i\n",ans);
			}
		}
	}
	return 0;
}