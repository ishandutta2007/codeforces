//CF 871B
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
const int N = 5005;
int f[N],g[N];
int p[N],b[N];
int x[N];
int main()
{
	int n,i,j,r,ans;
	cin>>n;
	for(i=0;i<n;i=i+1){
		cout<<"? 0 "<<i<<endl;
		cin>>f[i];
		cout<<"? "<<i<<" 0\n";
		cin>>g[i];
	}
	ans=0;
	for(i=0;i<n;i=i+1){
		p[0]=i;
		r=1;
		for(j=0;j<n;j=j+1)
			b[j]=i^f[j];
		for(j=0;j<n;j=j+1)
			p[j]=b[0]^g[j];
		for(j=0;j<n;j=j+1)
			if(p[b[j]]!=j){
				r=0;
				break;
			}
		if(r){
			if(!ans){
				for(j=0;j<n;j=j+1)
					x[j]=p[j];
			}
			ans++;
		}
	}
	cout<<"!\n"<<ans<<endl;
	for(i=0;i<n;i=i+1)
		cout<<x[i]<<' ';
	return 0;
}