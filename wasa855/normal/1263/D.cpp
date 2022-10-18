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
#define N 200005
string s[N];
int n;
int fa[N];
bool vis[N];
bool cc[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i='a';i<='z';i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int i='a';i<='z';i++) cc[i]=0;
		for(int j=0;j<s[i].length();j++)
		{
			vis[s[i][j]]=1;
			cc[s[i][j]]=1;
		}
		for(int j='a';j<='z';j++)
		{
			if(cc[j])
			{
				for(int k=j+1;k<='z';k++)
				{
					if(cc[k]) fa[find(j)]=find(k);
				}
				break;
			}
		}
	}
	int ans=0;
	for(int i='a';i<='z';i++)
	{
		if(vis[i]&&find(i)==i) ans++;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}