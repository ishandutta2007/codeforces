// CF 822B
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
char s[1111],t[1111];
int main()
{
	int n,m,i,j,ans,ss,p;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1)
		cin>>s[i];
	for(i=1;i<=m;i=i+1)
		cin>>t[i];
	ans=n;
	p=0;
	for(i=0;i+n<=m;i=i+1){
		ss=0;
		for(j=1;j<=n;j=j+1)
			if(t[i+j]!=s[j])
				ss++;
		ans=min(ans,ss);
		if(ss==ans)
			p=i;
	}
	cout<<ans<<endl;
	for(j=1;j<=n;j=j+1)
		if(t[p+j]!=s[j])
			cout<<j<<' ';
	cout<<endl;
	return 0;
}