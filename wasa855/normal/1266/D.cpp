#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
int in[N],out[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		in[u]+=w,out[v]+=w;
	}
	vector<int> a,b;
	vector<int> au,av,aw;
	for(int i=1;i<=n;i++)
	{
		int d=min(in[i],out[i]);
		in[i]-=d,out[i]-=d;
		if(in[i]) a.pb(i);
		if(out[i]) b.pb(i);
	}
//	cout<<"Passed\n";
	for(int i=0,j=0;i<a.size()&&j<b.size();)
	{
//		printf("%d %d\n",i,j);
		int d=min(in[a[i]],out[b[j]]);
		au.pb(a[i]),av.pb(b[j]),aw.pb(d);
		in[a[i]]-=d,out[b[j]]-=d;
		if(!in[a[i]]) i++;
		if(!out[b[j]]) j++;
	}
	cout<<au.size()<<endl;
	for(int i=0;i<au.size();i++)
	{
		printf("%lld %lld %lld\n",au[i],av[i],aw[i]);
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}