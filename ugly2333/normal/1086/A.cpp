//CF1086A
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
const int N = 1111;
int a[N][N],b[3],c[3];
int main()
{
	int n,i,j,x,y;
	for(i=0;i<3;i=i+1)
		cin>>b[i]>>c[i],a[b[i]][c[i]]=1;
	for(i=0;i<3;i=i+1){
		while(b[0]<b[1]&&b[0]<b[2]){
			b[0]++;
			a[b[0]][c[0]]=1;
		}
		while(b[0]>b[1]&&b[0]>b[2]){
			b[0]--;
			a[b[0]][c[0]]=1;
		}
		x=b[0],y=c[0];
		b[0]=b[1],c[0]=c[1];
		b[1]=b[2],c[1]=c[2];
		b[2]=x,c[2]=y;
	}
	for(i=0;i<3;i=i+1){
		while(c[0]<c[1]&&c[0]<c[2]){
			c[0]++;
			a[b[0]][c[0]]=1;
		}
		while(c[0]>c[1]&&c[0]>c[2]){
			c[0]--;
			a[b[0]][c[0]]=1;
		}
		x=b[0],y=c[0];
		b[0]=b[1],c[0]=c[1];
		b[1]=b[2],c[1]=c[2];
		b[2]=x,c[2]=y;
	}
	n=1000;
	x=0;
	for(i=0;i<=n;i=i+1)	
		for(j=0;j<=n;j=j+1)
			x+=a[i][j];
	cout<<x<<endl;
	for(i=0;i<=n;i=i+1)	
		for(j=0;j<=n;j=j+1)
			if(a[i][j])
				cout<<i<<' '<<j<<endl;
	return 0;
}