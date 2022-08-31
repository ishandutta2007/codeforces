//CF 995A
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
const int N = 111;
int n,k,x[N],y[N];
int a[5][N],r[5][N],c[5][N];
int ans;
vector<int> v[3];
void sv(int x,int y,int z){
	ans++;
	v[0].push_back(x);
	v[1].push_back(y);
	v[2].push_back(z);
}
int main()
{
	int i,j,o,s,xx,yy;
	cin>>n>>k;
	for(i=1;i<=n;i=i+1){
		cin>>o;
		x[o]=1,y[o]=i;
	}
	for(i=1;i<=n;i=i+1)
		cin>>a[2][i],r[2][i]=2,c[2][i]=i+1;
	for(i=1;i<=n;i=i+1)
		cin>>a[3][i],r[3][i]=3,c[3][i]=i-1;
	r[2][n]=3,c[2][n]=n,r[3][1]=2,c[3][1]=1;
	for(i=1;i<=n;i=i+1){
		cin>>o;
		x[o]=4,y[o]=i;
	}
	s=n+n-k;
	for(i=1;i<=n;i=i+1){
		if(a[2][i]){
			o=a[2][i];
			if(x[o]==1&&y[o]==i){
				a[2][i]=0;
				s++;
				sv(o,1,i);
			}
		}
		if(a[3][i]){
			o=a[3][i];
			if(x[o]==4&&y[o]==i){
				a[3][i]=0;
				s++;
				sv(o,4,i);
			}
		}
	}
	if(!s){
		cout<<-1;
		return 0;
	}
	while(s<n+n){
		for(j=2;j<=3;j=j+1)
			for(i=1;i<=n;i=i+1)
				if(a[j][i]&&!a[r[j][i]][c[j][i]])
					o=a[j][i],xx=j,yy=i;
		a[xx][yy]=0;
		a[r[xx][yy]][c[xx][yy]]=o;
		sv(o,r[xx][yy],c[xx][yy]);
		if(x[o]-1==((r[xx][yy]-1)^1)&&y[o]==c[xx][yy]){
			a[r[xx][yy]][c[xx][yy]]=0;
			s++;
			sv(o,x[o],y[o]);
		}
	}
	cout<<ans<<endl;
	for(i=0;i<ans;i=i+1){
		for(j=0;j<3;j=j+1)
			cout<<v[j][i]<<' ';
		cout<<endl;
	}
	return 0;
}