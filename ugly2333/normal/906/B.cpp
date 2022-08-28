//CF 906B
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
const int N = 111111;
vector<int> a[N],b[N];
int pi[N],pj[N];
vector<int> v;
int main()
{
	int n,m,f,i,j,x,t;
	cin>>n>>m;
	if(n==3&&m==3){
		cout<<"YES\n";
		cout<<"5 7 3\n";
		cout<<"9 2 4\n";
		cout<<"1 6 8\n";
		return 0;
	}
	if(n==1&&m==1){
		cout<<"YES\n";
		cout<<"1\n";
		return 0;
	}
	if(n<=3&&m<=3){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	if(m<=3){
		swap(n,m);
		f=1;
	}
	else	
		f=0;
	for(i=1;i<=n;i=i+1)
		for(j=0;j<=m;j=j+1)
			a[i].push_back((i-1)*m+j);
	if(m>3){
		for(i=1;i<=n;i=i+1){
			t=0;
			for(j=1;j<=m;j=j+1){
				x=a[i][j];
				if(x%2==0)
					pi[x]=i,pj[x]=++t;
			}
			for(j=1;j<=m;j=j+1){
				x=a[i][j];
				if(x%2==1)
					pi[x]=i,pj[x]=++t;
			}
			if(m%2==0&&i%2==0){
				for(j=1;j<=m;j=j+1){
					x=a[i][j];
					pj[x]=m+1-pj[x];
				}
			}
		}
	}
	if(f)
		swap(n,m);
	for(i=1;i<=n;i=i+1)
		b[i].resize(m+1);
	if(!f){
		for(i=1;i<=n;i=i+1)
			for(j=1;j<=m;j=j+1)
				x=(i-1)*m+j,b[pi[x]][pj[x]]=x;
	}
	else{
		for(i=1;i<=n;i=i+1)
			for(j=1;j<=m;j=j+1)
				x=(i-1)*m+j,t=(j-1)*n+i,b[pj[t]][pi[t]]=x;
	}
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=m;j=j+1)
			cout<<b[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}