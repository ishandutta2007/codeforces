#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int ch[N][30],f[N],l[N],las=1,sz=1,t[N],a[N],dp[N];
long long ans;
string s;
void add(int x)
{
	int c=++sz,p=las;l[c]=l[las]+1,dp[c]=1;
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
			memcpy(ch[nq],ch[q],sizeof(ch[nq]));
			f[nq]=f[q],l[nq]=l[p]+1;
			while(p&&ch[p][x]==q)
			{
				ch[p][x]=nq;
				p=f[p];
			}
			f[q]=f[c]=nq;
		}
	}
	las=c;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++)
		add(s[i]-'a');
	for(int i=1;i<=sz;i++)
		t[l[i]]++;
	for(int i=1;i<=sz;i++)
		t[i]+=t[i-1];
	for(int i=1;i<=sz;i++)
		a[t[l[i]]--]=i;
	for(int i=sz;i>=1;i--)
	{
		int u=a[i];
		dp[f[u]]+=dp[u];
		ans+=1ll*(l[u]-l[f[u]])*dp[u]*(dp[u]+1)/2;
	}
	cout<<ans<<endl;
	return 0;
}