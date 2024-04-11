//CF 779B
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
char c[100];
int main()
{
	int n,k,i,ans;
	cin>>c;
	cin>>k;
	n=strlen(c);
	n=n-1;
	ans=0;
	while(k>0&&n>=0){
		if(c[n]=='0')
			k=k-1;
		else
			ans=ans+1;
		n=n-1;
	}
	if(k>0)
		ans=strlen(c)-1;
	cout<<ans<<endl;
	return 0;
}