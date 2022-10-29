#include <iostream>
#include <map>
using namespace std;
int n,x,cnt;
string now;
map <string,int> mp;
string S[10005];
int qwq[10005];
inline void dfs(int s)
{
	if(!s)
	{
		int flag=1;
		for(int i=0;i<now.size();i++)
		{
			int S=0;
			for(int j=i;j<now.size();j++)
			{
				S+=now[j]-'0';
				if(x%S==0&&S!=x) flag=0;
			}
		}
		if(!flag) return ;
	//	cout << now << "\n";
		for(int i=0;i<now.size();i++)
			if(!mp[now.substr(0,i+1)]) mp[now.substr(0,i+1)]=++cnt,S[cnt]=now.substr(0,i+1);
		qwq[mp[now]]=1;
	}
	for(int i=1;i<=min(s,9);i++)
	{
		now+=(char)i+'0';
		dfs(s-i);
		now.pop_back();
	}
}
int dp[1005][10005];//ij 
int nxt[10005][10];
int main()
{
	string s;
	cin >> s >> x;
	n=s.size(),s=' '+s;
	dfs(x);
	for(int i=0;i<=cnt;i++)
	{
		string t=S[i];
		for(int k=1;k<=9;k++)
		{
			t+=(char)(k+'0');
			for(int l=0;l<t.size();l++)
			{
				if(mp[t.substr(l)])
				{
					nxt[i][k]=mp[t.substr(l)];
					break;
				}
			}
			t=t.substr(0,t.size()-1);
			//cout << t << " " << k << " " << nxt[i][k] << "\n";
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=cnt;j++)
			dp[i][j]=-1e9;
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=cnt;j++)
		{
			dp[i][j]=max(dp[i][j],dp[i-1][j]); 
			if(qwq[j]) continue;
			dp[i][nxt[j][s[i]-'0']]=max(dp[i][nxt[j][s[i]-'0']],dp[i-1][j]+1);
		}
		for(int j=0;j<=cnt;j++)
			if(qwq[j]) dp[i][j]=0;
	}
	int mx=0;
	for(int i=0;i<=cnt;i++)
		if(!qwq[i]) mx=max(mx,dp[n][i]);
	cout << n-mx;
//if(n-mx==195) cout << n << " " << x << "\n";
	return 0;
}