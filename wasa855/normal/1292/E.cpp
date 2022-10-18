#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 55
char ans[N],rev[N*10],to[N*10];
map<string,int> used;
int query(string s)
{
	if(used[s]) return 0;
	used[s]=1;
	for(char &i:s) i=rev[i];
	cout<<"? "<<s<<endl;
	int R=read();
	for(int i=1;i<=R;i++)
	{
		int x=read();
		for(int j=0;j<(int)s.length();j++) ans[x+j]=to[s[j]];
	}
	return R;
}
bool vis[N];
void solve1(string s)
{
	queue<int> q;
	for(int i=1;i<=4;i++)
	{
		if(!ans[i])
		{
			if(ans[i-1]||ans[i+1]) q.push(i),vis[i]=1;
		}
	}
	for(int i=1;i<=4;i++)
	{
		if(!ans[i]&&!vis[i]) q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front(); q.pop();
//		cout<<u<<endl;
//		if(ans[u-1])
		{
			for(char i='A';i<='B';i++)
			{
				if(ans[u-1])
				{
					string s="";
					s+=ans[u-1];
					s+=i;
					if(used[s]) continue;
				}
				if(ans[u+1])
				{
					string s="";
					s+=i;
					s+=ans[u+1];
					if(used[s]) continue;
				}
				string s="";
				int l=u,r=u;
				while(ans[l-1]) l--;
				while(ans[r+1]) r++;
				for(int j=l;j<u;j++) s+=ans[j];
				s+=i;
				for(int j=u+1;j<=r;j++) s+=ans[j];
				if(query(s)) break;
			}
			if(!ans[u]) ans[u]='C';
		}
		/*
		else
		{
			if(ans[u+1]=='A')
			{
				if(query("AA")) continue;
				if(query("BA")) continue;
				ans[u]='C';
			}
			else if(ans[u+1]=='B')
			{
				if(query("AB")) continue;
				if(query("BB")) continue;
				ans[u]='C';
			}
			else
			{
				if(query("AC")) continue;
				if(query("BC")) continue;
				ans[u]='C';
			}
		}
		*/
	}
}
void work1()
{
	if(query("AA")) solve1("AA");
	else if(query("AB")) solve1("AB");
	else if(query("AC")) solve1("AC");
	else if(query("BC")) solve1("BC");
	else if(query("BBB"))
	{
		if(!ans[1]) ans[1]='C';
		else if(!ans[4]) ans[4]='A';
	}
	else if(query("CCC"))
	{
		if(!ans[4])
		{
			if(!query("CCCA")) ans[4]='B';
		}
	}
	else if(query("CCB"))
	{
		if(!query("CCBA")) ans[4]='B';
	}
	else
	{
		ans[1]='C';
		ans[2]='B';
		ans[3]='B';
		ans[4]='A';
	}
}
void answer(int n)
{
	cout<<"! ";
	for(int i=1;i<=n;i++) putchar(rev[ans[i]]);
	cout<<endl;
	assert(read()==1);
}
void work2(int n)
{
	query("AA");
	query("AB");
	query("AC");
	query("BB");
	query("CB");
	for(int i=2;i<n;i++)
	{
		if(!ans[i]) ans[i]='C';
	}
	string s="B";
	for(int i=2;i<n;i++) s+=ans[i];
	query(s);
	if(!ans[1]) ans[1]='C';
	s="";
	for(int i=1;i<n;i++) s+=ans[i];
	s+='A';
	query(s);
	if(!ans[n]) ans[n]='C';
}
signed main()
{
	rev['A']='C';
	rev['B']='H';
	rev['C']='O';
	to['C']='A';
	to['H']='B';
	to['O']='C';
	int T=read();
	while(T--)
	{
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		used.clear();
		int n=read();
		if(n==4) work1();
		else work2(n);
		answer(n);
	}
	return 0;
}