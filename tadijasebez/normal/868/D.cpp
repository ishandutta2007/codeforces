#include <bits/stdc++.h>
using namespace std;
const int N=205;
string pre[N],suf[N];
set<string> all[N][13];
void Extend(int id, string s)
{
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;i+j<s.size() && j<13;j++)
		{
			all[id][j].insert(s.substr(i,j+1));
		}
	}
}
void Merge(int id, int l, int r)
{
	for(int i=0;i<13;i++)
	{
		for(auto it:all[l][i]) all[id][i].insert(it);
		for(auto it:all[r][i]) all[id][i].insert(it);
	}
	Extend(id,suf[l]+pre[r]);
	pre[id]=pre[l];
	suf[id]=suf[r];
	for(int i=0;i<pre[r].size();i++) if(pre[id].size()<13) pre[id]+=pre[r][i];
	for(int i=(int)suf[l].size()-1;i>=0;i--) if(suf[id].size()<13) suf[id]=suf[l][i]+suf[id];
}
int main()
{
	int n,q,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		string s;
		cin >> s;
		Extend(i,s);
		if(s.size()<13) pre[i]=suf[i]=s;
		else pre[i]=s.substr(0,13),suf[i]=s.substr(s.size()-13,13);
	}
	scanf("%i",&q);
	while(q--)
	{
		n++;
		int l,r;
		scanf("%i %i",&l,&r);
		Merge(n,l,r);
		int sol=0;
		for(i=0;i<13;i++)
		{
			if(all[n][i].size()!=(1<<(i+1))) break;
			sol=i+1;
		}
		printf("%i\n",sol);
	}
	return 0;
}