//CF 900D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
map<int,LL> M;
LL s[222222];
int main()
{
	int n,i,x;
	LL ss,ans;
	ULL ans1,ans2;
	scanf("%d",&n);
	ss=0,ans=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		ss+=x;
		s[i]=(LL)x*i-ss;
		if(M.find(x-1)!=M.end())
			ans-=M[x-1];
		if(M.find(x+1)!=M.end())
			ans+=M[x+1];
		if(M.find(x)==M.end())
			M[x]=1;
		else
			M[x]++;
	}
	s[0]=ans;
	ans1=0,ans2=0;
	for(i=0;i<=n;i=i+1){
		if(s[i]>0)
			ans1+=s[i];
		else
			ans2+=(-s[i]);
	}
	if(ans1>=ans2)
		cout<<ans1-ans2<<endl;
	else
		cout<<'-'<<ans2-ans1<<endl;
	return 0;
}