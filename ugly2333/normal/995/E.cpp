//CF 995E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int H = 16;
const int N = 1<<18;
int p;
int fpow(int x,int y=p-2){
	if(!y)
		return 1;
	LL z=fpow(x,y>>1);
	z=z*z%p;
	if(y&1)
		z=z*x%p;
	return z;
}
int l[2],a[2][N];
void dfs(int k,int u,int t,int e){
	u=(u+p)%p;
	a[e][l[e]++]=u;
	if(k==H)
		return;
	k++;
	if(t!=2)
		dfs(k,u+1,1,e);
	if(t!=1)
		dfs(k,u-1,2,e);
	if(t!=3)
		dfs(k,fpow(u),3,e);
}
int f[2];
vector<int> v[2];
void getans(int k,int u,int t,int e,int j){
	u=(u+p)%p;
	if(!f[e])
		v[e].push_back(t);
	if(!f[e]&&u==j){
		f[e]=1;
		return;
	}
	if(k==H){
		if(!f[e])
			v[e].pop_back();
		return;
	}
	k++;
	if(t!=2)
		getans(k,u+1,1,e,j);
	if(t!=1)
		getans(k,u-1,2,e,j);
	if(t!=3)
		getans(k,fpow(u),3,e,j);
	if(!f[e])
		v[e].pop_back();
}
int main()
{
	int i,j,x,y,z;
	cin>>x>>y>>p;
	dfs(0,x,0,0),dfs(0,y,0,1);
	sort(a[0],a[0]+l[0]);
	for(i=0;i<l[1];i=i+1){
		j=lower_bound(a[0],a[0]+l[0],a[1][i])-a[0];
		if(j<l[0]&&a[0][j]-a[1][i]<=160)
			break;
	}
	//cout<<a[0][j]<<' '<<a[1][i]<<endl;
	z=a[0][j]-a[1][i];
	getans(0,x,0,0,a[0][j]),getans(0,y,0,1,a[1][i]);
	cout<<v[0].size()-1+z+v[1].size()-1<<endl;
	for(i=1;i<v[0].size();i=i+1)
		cout<<v[0][i]<<' ';
	for(i=0;i<z;i=i+1)
		cout<<2<<' ';
	for(i=v[1].size()-1;i>0;i=i-1){
		if(v[1][i]<3)
			v[1][i]=3-v[1][i];
		cout<<v[1][i]<<' ';
	}
	/*for(i=1;i<v[0].size();i=i+1){
		j=v[0][i];
		if(j==1)
			x=(x+1)%p;
		if(j==2)
			x=(x-1+p)%p;
		if(j==3)
			x=fpow(x);
	}
	x=(x-z+p)%p;
	for(i=v[1].size()-1;i>0;i=i-1){
		j=v[1][i];
		if(j==1)
			x=(x+1)%p;
		if(j==2)
			x=(x-1+p)%p;
		if(j==3)
			x=fpow(x);
	}
	cout<<x<<' '<<y<<endl;*/
	return 0;
}