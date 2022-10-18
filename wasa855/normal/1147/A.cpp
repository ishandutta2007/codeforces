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
#define N 100005
int a[N];
vector<int> v[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		a[i]=read();
		v[a[i]].pb(i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(v[i].size()==0)
		{
			ans+=3;
			if(i==1||i==n) ans--;
		}
		else
		{
			int ms=v[i][0];
			if(i!=1&&(v[i-1].size()==0||v[i-1].back()<ms)) ans++;
			if(i!=n&&(v[i+1].size()==0||v[i+1].back()<ms)) ans++;
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}


//