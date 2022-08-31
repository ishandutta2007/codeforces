//CF 798B
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
char c[111][111];
int main()
{
	int i,j,k,l,n,s,m,ans,f,ss;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>c[i];
	m=strlen(c[1]);
	ans=1<<30;
	for(i=1;i<=n;i=i+1){
		ss=0;
		for(j=1;j<=n;j=j+1){
			s=1<<30;
			for(k=0;k<m;k=k+1){
				f=0;
				for(l=0;l<m;l=l+1)
					if(c[i][l]!=c[j][(l+k)%m])
						f=1;
				if(f==0)
					s=min(s,k);
			}
			if(s==1<<30){
				cout<<-1<<endl;
				return 0;
			}
			ss+=s;
		}
		ans=min(ans,ss);
	}
	cout<<ans<<endl;
	return 0;
}