#include<bits/stdc++.h>
using namespace std;
const int N=305;
int in[N][5];
string dp[N][5],ans[N];
queue<pair<int,int>>q;
void upd(int v,int r,string p)
{
	if(dp[v][r]=="@"||(p.size()<dp[v][r].size()||(p.size()==dp[v][r].size()&&p<dp[v][r])))
	{
		dp[v][r]=p;
		if(!in[v][r])
		{
			q.push(make_pair(v,r));
			in[v][r]=1;
		}
	}
}
string tr(int x)
{
	string s="";
	for(int i=128;i;i>>=1)
	{
		if(x&i)
			s+="1";
		else
			s+="0";
	}
	return s;
}
void sol()
{
	for(int i=0;i<256;i++)
		for(int j=0;j<=3;j++)
			dp[i][j]="@",ans[i]="@";
	upd(0b00001111,0,"x");
	upd(0b00110011,0,"y");
	upd(0b01010101,0,"z");
	while(!q.empty())
	{
		int u=q.front().first,mu=q.front().second;
		q.pop();
		in[u][mu]=0;
		if(mu)
			upd(((~u)&255),mu,"!("+dp[u][mu]+")");
		else
			upd(((~u)&255),1,"!"+dp[u][mu]);
		for(int v=0;v<256;v++)
		{
			for(int mv=0;mv<=3;mv++)
			{
				if(dp[v][mv]=="@")
					continue;
				string x=dp[u][mu],y=dp[v][mv];
				if(mu>2)
					x="("+x+")";
				if(mv>2)
					y="("+y+")";
				upd(u&v,max(2,max(mu,mv)),x+"&"+y);
				upd(u|v,3,dp[u][mu]+"|"+dp[v][mv]);
				upd(u&v,max(2,max(mu,mv)),y+"&"+x);
				upd(u|v,3,dp[v][mv]+"|"+dp[u][mu]);
			}
		}
	}
	for(int i=0;i<256;i++)
		for(int j=0;j<=3;j++)
			if(dp[i][j]!="@"&&(ans[i]=="@"||dp[i][j].size()<ans[i].size()||(dp[i][j].size()==ans[i].size()&&dp[i][j]<ans[i])))
				ans[i]=dp[i][j];
}
int main()
{
	ios::sync_with_stdio(0);
	sol();
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		int x=0;
		cin>>s;
		for(int i=0;i<8;i++)
			x=x*2+s[i]-'0';
		cout<<ans[x]<<endl;
	}
	return 0;
}