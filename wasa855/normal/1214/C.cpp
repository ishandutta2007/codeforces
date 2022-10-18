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
string s;
signed main()
{
	int n;
	cin>>n;
	if(n%2==1)
	{
		cout<<"No\n";
		return 0;
	}
	cin>>s;
	int ans=0;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(') cnt++;
	}
	if(cnt*2!=n) cout<<"No\n",exit(0);
	stack<int> t;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(') t.push('(');
		else
		{
			if(!t.empty()) t.pop();
			else if(ans==0) ans=1;
			else cout<<"No\n",exit(0);
		}
	}
	cout<<"Yes\n";
	return 0;
}