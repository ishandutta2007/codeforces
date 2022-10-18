#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
int sx[30],sy[30];
void work()
{
	memset(sx,0,sizeof(sx));
	memset(sy,0,sizeof(sy));
	string s,t,p;
	cin>>s>>t>>p;
	int sl=s.length(),tl=t.length(),pl=p.length();
	for(int i=0;i<sl;i++)
	{
		sx[s[i]-'a']++;
	}
	for(int i=0;i<pl;i++)
	{
		sx[p[i]-'a']++;
	}
	for(int i=0;i<tl;i++)
	{
		sy[t[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(sx[i]<sy[i])
		{
			cout<<"NO\n";
			return ;
		}
	}
	int j=0;
	for(int i=0;i<sl;i++)
	{
		while(j<tl&&t[j]!=s[i])
		{
			j++;
		}
		if(j==tl)
		{
			cout<<"NO\n";
			return ;
		}
		j++;
	}
	cout<<"YES\n";
	
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--) work();
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//ascsafea