#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int mod1=1000000007;
const int mod2=1000000009;
const int arg1=20040911;
const int arg2=20050715;
int pw1[N],pw2[N];
int n,m;
char str[N];
vector<int>v;
pair<int,int>h[26][N];
pair<int,int>get(pair<int,int>h[],int lef,int rig)
{
	pair<int,int>my=h[rig];
	lef--;
	if(lef>=0)
	{
		my.first=(my.first-(long long)(h[lef].first)*pw1[rig-lef]%mod1+mod1)%mod1;
		my.second=(my.second-(long long)(h[lef].second)*pw2[rig-lef]%mod2+mod2)%mod2;
	}
	return my;
} 
int main()
{
	pw1[0]=pw2[0]=1;
	for(int i=1;i<N;i++)
	{
		pw1[i]=(long long)pw1[i-1]*arg1%mod1;
		pw2[i]=(long long)pw2[i-1]*arg2%mod2;
	}
	scanf("%d%d",&n,&m);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		{
			h[j][i].first=((long long)(h[j][i-1].first)*arg1+(long long)(1+('a'+j==str[i])))%mod1;
			h[j][i].second=((long long)(h[j][i-1].second)*arg2+(long long)(1+('a'+j==str[i])))%mod2;
		}
	}
	while(m--)
	{
		int x,y,len;
		scanf("%d%d%d",&x,&y,&len);
		multiset<pair<int,int>>a,b;
		for(int i=0;i<26;i++)
		{
			a.insert(get(h[i],x,x+len-1));
			b.insert(get(h[i],y,y+len-1));
		}
		printf("%s\n",a==b?"YES":"NO");
	}
	return 0;
}