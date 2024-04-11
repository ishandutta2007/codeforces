// CF 818B
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
int a[111],s[111],ss[111];
int main()
{
	int n,m,i,x,p;
	cin>>n>>m>>p;
	for(i=2;i<=m;i=i+1){
		cin>>x;
		if(a[p]){
			if((p+a[p]-1)%n+1!=x){
				cout<<-1<<endl;
				return 0;
			}
		}
		else
			a[p]=(x+n-p-1)%n+1;
		p=x;
	}
	for(i=1;i<=n;i=i+1)
		s[a[i]]++;
	p=0;
	for(i=1;i<=n;i=i+1){
		if(s[i]>1){
			cout<<-1<<endl;
			return 0;
		}
		if(!s[i]){
			p++;
			ss[p]=i;
		}
	}
	p=0;
	for(i=1;i<=n;i=i+1){
		if(a[i])
			cout<<a[i]<<' ';
		else{
			p++;
			cout<<ss[p]<<' ';
		}
	}
	return 0;
}