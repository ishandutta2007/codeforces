#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
bitset<N> ans,x[4];
int mp[205];
int a[N][4];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	mp['A']=0,mp['C']=1,mp['G']=2,mp['T']=3;
	int n,m,k;
	cin>>n>>m>>k;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<n;i++)
	{
		a[max(0,i-k)][mp[s[i]]]++;
		a[min(n,i+k+1)][mp[s[i]]]--;
	}
	for(int i=0;i<n;i++)
	{
		ans[i]=1;
		for(int j=0;j<4;j++)
		{
			if(i!=0) a[i][j]+=a[i-1][j];
			if(a[i][j]) x[j][i]=1;
		}
	}
	for(int i=0;i<m;i++)
	{
		ans&=(x[mp[t[i]]]>>i);
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(ans[i]==1) res++;
	}
	cout<<res<<endl;
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}