#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 205
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	string a;
	cin>>a;
	vector<int> ans;
	string s=a;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='W')
		{
			ans.pb(i);
			s[i]='B';
			if(s[i+1]=='W') s[i+1]='B';
			else s[i+1]='W';
		}
	}
	if(s[n-1]=='B')
	{
		cout<<ans.size()<<endl;
		for(int i:ans) printf("%d ",i+1);
		cout<<"\n";
		return 0;
	}
	ans.clear();
	s=a;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='B')
		{
			ans.pb(i);
			s[i]='W';
			if(s[i+1]=='W') s[i+1]='B';
			else s[i+1]='W';
		}
	}
	if(s[n-1]=='W')
	{
		cout<<ans.size()<<endl;
		for(int i:ans) printf("%d ",i+1);
		cout<<"\n";
		return 0;
	}
	cout<<"-1\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

//