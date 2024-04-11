//CF 894A
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
int n;
char ch[111];
int main()
{
	int i,j,k,ans;
	cin>>ch;
	n=strlen(ch);
	ans=0;
	for(i=0;i<n;i=i+1)
		for(j=i+1;j<n;j=j+1)
			for(k=j+1;k<n;k=k+1)
				if(ch[i]=='Q'&&ch[j]=='A'&&ch[k]=='Q')
					ans++;
	cout<<ans<<endl;
	return 0;
}