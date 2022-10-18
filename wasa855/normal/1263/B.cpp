#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 15
string s[N];
bool ok[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		ok[i]=0;
	}
	map<string,bool> vis;
	for(int i=1;i<=n;i++)
	{
		if(!vis[s[i]])
		{
			vis[s[i]]=1;
			ok[i]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!ok[i])
		{
			ans++;
			for(int j='0';j<='9';j++)
			{
				s[i][0]=j;
				if(!vis[s[i]])
				{
					vis[s[i]]=1;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<s[i]<<endl;
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}