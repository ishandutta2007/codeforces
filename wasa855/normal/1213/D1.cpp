#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N];
vector<int> v[N];
signed main()
{
	int n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		while(a[i])
		{
			v[a[i]].push_back(cnt);
			cnt++,a[i]/=2;
		}
	}
	int ans=(int)N*(int)N;
	for(int i=1;i<N;i++)
	{
		if(v[i].size()>=k)
		{
			sort(v[i].begin(),v[i].end());
			int res=0;
			for(int j=0;j<k;j++) res+=v[i][j];
			if(res<ans) ans=res;
		}
	}
	cout<<ans<<endl;
	return 0;
}