#include <bits/stdc++.h>
using namespace std;
const int N=3050;
string s[N],t[N],a,b,pre,suf;
int l[N],r[N],i,j,k,n;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(i=1;i<=n;i++) cin >> s[i];
	for(i=1;i<=n;i++) cin >> t[i];
	for(i=1;i<=n;i++)
	{
		l[i]=N,r[i]=-1;
		if(s[i]==t[i]) continue;
		for(j=0;j<s[i].size();j++) if(s[i][j]!=t[i][j]) l[i]=min(l[i],j),r[i]=max(r[i],j);
		if(a.empty())
		{
			a=s[i].substr(l[i],r[i]-l[i]+1);
			b=t[i].substr(l[i],r[i]-l[i]+1);
			pre=s[i].substr(0,l[i]);
			suf=s[i].substr(r[i]+1);
			reverse(pre.begin(),pre.end());
		}
		else
		{
			if(a!=s[i].substr(l[i],r[i]-l[i]+1) || b!=t[i].substr(l[i],r[i]-l[i]+1)) return cout << "NO\n",0;
			string pt,st;
			pt=s[i].substr(0,l[i]);
			st=s[i].substr(r[i]+1);
			reverse(pt.begin(),pt.end());
			for(j=0;j<pt.size() && j<pre.size() && pt[j]==pre[j];j++);
			pre.resize(j);
			for(j=0;j<st.size() && j<suf.size() && st[j]==suf[j];j++);
			suf.resize(j);
		}
	}
	reverse(pre.begin(),pre.end());
	a=pre+a+suf;
	b=pre+b+suf;
	vector<int> f(a.size()+1,0);
	for(i=1,j=0;i<a.size();i++)
	{
		while(j!=0 && a[i]!=a[j]) j=f[j];
		if(a[i]==a[j]) j++;
		f[i+1]=j;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0,k=0;j<s[i].size();j++)
		{
			while(k!=0 && s[i][j]!=a[k]) k=f[k];
			if(s[i][j]==a[k]) k++;
			if(k==a.size()) break;
		}
		if(j!=s[i].size())
		{
			int st=j-a.size()+1;
			for(j=0;j<a.size();j++) s[i][st+j]=b[j];
		}
		if(s[i]!=t[i]) return cout << "NO\n",0;
	}
	cout << "YES\n";
	cout << a << "\n";
	cout << b << "\n";
	return 0;
}