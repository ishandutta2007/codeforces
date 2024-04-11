// CF 814B
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
int a[1111],b[1111],c[1111];
int main()
{
	int n,i,f,s,x,y;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	for(i=1;i<=n;i=i+1)
		cin>>b[i];
	f=0;
	s=0;
	for(i=1;i<=n;i=i+1){
		if(a[i]!=b[i]){
			if(f)
				s=i;
			else
				f=i;
		}
		else
			c[a[i]]=1;
	}
	x=0;
	y=0;
	for(i=1;i<=n;i=i+1){
		if(!c[i]){
			if(x)
				y=i;
			else
				x=i;
		}
	}
	if(s==0)
		a[f]=x;
	else{
		if(a[f]!=b[s]&&c[a[f]]==0&&c[b[s]]==0)
			a[s]=b[s];
		else if(a[s]!=b[f]&&c[a[s]]==0&&c[b[f]]==0)
			a[f]=b[f];
	}
	for(i=1;i<=n;i=i+1)
		cout<<a[i]<<' ';
	return 0;
}