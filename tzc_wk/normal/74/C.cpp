#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int get(int x,int y){
	if(x==1)		return y;
	else if(x==n)	return 2*m+n-1-y;
	else if(y==1)	return 2*m+2*n-2-x;
	else if(y==m)	return m+x-1;
}
int f[4000005];
void init(){for(int i=1;i<=2*(n+m)-4;i++)	f[i]=i;}
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
void link(int x,int y){if(find(x)!=find(y))	f[find(x)]=find(y);}
signed main(){
	cin>>n>>m;
	init();
	if(n<m)	swap(n,m);
	for(int i=1;i<=n;i++){
		if(i<=m)
			link(get(i,1),get(1,i)),link(get(i,m),get(1,m-i+1));
		else
			link(get(i,1),get(i-m+1,m)),link(get(i,m),get(i-m+1,1));
		if(i>=n-m+1)
			link(get(i,1),get(n,n-i+1)),link(get(i,m),get(n,m-n+i));
		else
			link(get(i,1),get(m+i-1,m)),link(get(i,m),get(m+i-1,1));
	}
	int ans=0;
	for(int i=1;i<=2*m+2*n-4;i++)	if(f[i]==i)	ans++;
	cout<<ans<<endl;
}//