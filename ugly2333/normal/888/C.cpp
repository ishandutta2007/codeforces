//CF 888C
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
char ch[111111];
int p[33],s[33];
int main()
{
	int n,i,j,ans;
	scanf("%s",&ch);
	n=strlen(ch);
	for(j=1;j<=26;j=j+1)
		p[j]=-1,s[j]=1;
	for(i=0;i<n;i=i+1){
		j=ch[i]-96;
		s[j]=max(s[j],i-p[j]);
		p[j]=i;
	}
	for(j=1;j<=26;j=j+1)
		s[j]=max(s[j],n-p[j]);
	ans=n;
	for(j=1;j<=26;j=j+1)
		ans=min(ans,s[j]);
	cout<<ans<<endl;
	return 0;
}