//CF 803E
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
int a[1111],dp[1111][2222],n,k,f;
void dfs(int t,int p)
{
	if(dp[t][p+1111]||f)
		return;
	dp[t][p+1111]=1;
	if(t==n){
		if(f)
			return;
		if(p==k||p==-k){
			int i;
			for(i=1;i<=n;i=i+1){
				if(a[i]==1)
					cout<<'W';
				if(a[i]==0)
					cout<<'D';
				if(a[i]==-1)
					cout<<'L';
			}
			cout<<endl;
			f=1;
		}
		return;
	}
	if(p>=k||p<=-k)
		return;
	t++;
	if(a[t]!=2)
		dfs(t,p+a[t]);
	else{
		int i;
		for(i=-1;i<=1;i=i+1){
			a[t]=i;
			dfs(t,p+a[t]);
		}
	}
	return;
}
int main()
{
	int i;
	char c;
	cin>>n>>k;
	for(i=1;i<=n;i=i+1){
		cin>>c;
		if(c=='W')
			a[i]=1;
		if(c=='D')
			a[i]=0;
		if(c=='L')
			a[i]=-1;
		if(c=='?')
			a[i]=2;
	}
	dfs(0,0);
	if(f==0)
		cout<<"NO\n";
	return 0;
}