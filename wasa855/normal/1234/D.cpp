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
#define N 200005
int lowbit(int x){return x&(-x);}
int t[30][N];
int n;
char s[N];
void add(int i,int u,int d)
{
	while(u<=n)
	{
		t[i][u]+=d;
		u+=lowbit(u);
	}
}
int sum(int i,int u)
{
	int ans=0;
	while(u)
	{
		ans+=t[i][u];
		u-=lowbit(u);
	}
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i]-'a'+1;
		add(s[i],i,1);
	}
	int opt,l,r;
	char x;
	int m=read();
	for(int i=1;i<=m;i++)
	{
		opt=read();
		if(opt==1)
		{
			l=read();cin>>x;
			add(s[l],l,-1);
			add(x-'a'+1,l,1);
			s[l]=x-'a'+1;
		}
		else
		{
			l=read(),r=read();
			int ans=0;
			for(int i=1;i<=26;i++)
			{
				if(sum(i,r)-sum(i,l-1)>0) ans++;
			}
			cout<<ans<<endl;
		}
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}