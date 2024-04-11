#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,ch[N][26],f[N],l[N],las=1,sz=1,a[N],t[N],dp[N],v[N];
char s[N];
vector<int>a1,a2;
void add(int x)
{
	int c=++sz,p=las;
	l[c]=l[p]+1,dp[c]=1;
	while(p&&!ch[p][x])
	{
		ch[p][x]=c;
		p=f[p];
	}
	if(!p)
		f[c]=1;
	else
	{
		int q=ch[p][x];
		if(l[p]+1==l[q])
			f[c]=q;
		else
		{
			int nq=++sz;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			f[nq]=f[q],l[nq]=l[p]+1;
			while(p&&ch[p][x]==q)
			{
				ch[p][x]=nq;
				p=f[p];
			}
			f[c]=f[q]=nq;
		}
	}
	las=c;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		add(s[i]-'A');
	int p=las;
	while(p)
	{
		v[p]=1;
		p=f[p];
	}
	for(int i=1;i<=sz;i++)
		t[l[i]]++;
	for(int i=1;i<=sz;i++)
		t[i]+=t[i-1];
	for(int i=1;i<=sz;i++)
		a[t[l[i]]--]=i;
	for(int i=sz;i>=1;i--)
		dp[f[a[i]]]+=dp[a[i]];
	p=1;
	for(int i=1;i<=n;i++)
	{
		int x=s[i]-'A';
		p=ch[p][x];
		if(v[p])
		{
			a1.push_back(i);
			a2.push_back(dp[p]);
		}
	}
	printf("%d\n",a1.size());
	for(int i=0;i<a1.size();i++)
		printf("%d %d\n",a1[i],a2[i]);
	return 0;
}