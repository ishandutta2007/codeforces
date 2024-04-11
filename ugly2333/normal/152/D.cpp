//CF 152D
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
typedef double DB;
const int N = 1005;
char a[N][N];
int n,m,b[N],x[N],y[N];
int c[11],f[N][11],g[N][4];
int main()
{
	int i,j,k,s,l,r,u,d,w,p;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i=i+1)
		scanf("%s",a[i]);
	
	w=0,p=0;
	for(i=0;i<n-1;i=i+1){
		b[i]=1;
		s=0;
		for(j=0;j<m;j=j+1){
			if(a[i][j]!=a[i+1][j])
				b[i]=0;
			if(a[i][j]=='#')
				s++;
		}
		l=0;
		for(j=0;j<m-2;j=j+1)
			if(a[i][j]=='#'&&a[i][j+1]=='#'&&a[i][j+2]=='#')
				l=1;
		if(!b[i]&&!s&&!w)
			b[i]=1,w=1;
		if(b[i]&&l){
			if(p<4){
				b[i]=0;
				p++;
			}
		}
		else
			p=0;
	}
	b[n-1]=0;
	s=0;
	for(j=0;j<m;j=j+1)
		if(a[n-1][j]=='#')
			s++;
	if(!s)
		b[n-1]=1;
	k=0;
	for(i=0;i<n;i=i+1){
		if(b[i])
			continue;
		for(j=0;j<m;j=j+1)
			a[k][j]=a[i][j];
		x[k++]=i+1;
	}
	n=k;
	
	w=0,p=0;
	for(j=0;j<m-1;j=j+1){
		b[j]=1;
		s=0;
		for(i=0;i<n;i=i+1){
			if(a[i][j]!=a[i][j+1])
				b[j]=0;
			if(a[i][j]=='#')
				s++;
		}
		l=0;
		for(i=0;i<n-2;i=i+1)
			if(a[i][j]=='#'&&a[i+1][j]=='#'&&a[i+2][j]=='#')
				l=1;
		if(!b[j]&&!s&&!w)
			b[j]=1,w=1;
		if(b[j]&&l){
			if(p<4){
				b[j]=0;
				p++;
			}
		}
		else
			p=0;
	}
	b[m-1]=0;
	s=0;
	for(i=0;i<n;i=i+1)
		if(a[i][m-1]=='#')
			s++;
	if(!s)
		b[m-1]=1;
	k=0;
	for(j=0;j<m;j=j+1){
		if(b[j])
			continue;
		for(i=0;i<n;i=i+1)
			a[i][k]=a[i][j];
		y[k++]=j+1;
	}
	m=k;
	
	/*cout<<n<<m<<endl;
	for(i=0;i<n;i=i+1){
		for(j=0;j<m;j=j+1)
			cout<<a[i][j];
		cout<<endl;
	}*/
	if(n>9||m>9){
		printf("NO");
		return 0;
	}
	for(i=0;i<n;i=i+1)
		for(j=0;j<m;j=j+1)
			if(a[i][j]=='#')
				c[i]|=(1<<j);
	k=0;
	for(l=0;l<m;l=l+1)
		for(r=l+2;r<m;r=r+1)
			for(u=0;u<n;u=u+1)
				for(d=u+2;d<n;d=d+1){
					for(i=u;i<=d;i=i+1)
						f[k][i]|=(1<<l)|(1<<r);
					for(j=l;j<=r;j=j+1)
						f[k][u]|=(1<<j),f[k][d]|=(1<<j);
					g[k][0]=x[u],g[k][1]=y[l];
					g[k][2]=x[d],g[k][3]=y[r];
					k++;
				}
	for(l=0;l<k;l=l+1)
		for(r=l;r<k;r=r+1){
			s=1;
			for(i=0;i<n;i=i+1)
				if((f[l][i]|f[r][i])!=c[i])
					s=0;
			if(s){
				printf("YES\n");
				for(i=0;i<4;i=i+1)
					printf("%d ",g[l][i]);
				printf("\n");
				for(i=0;i<4;i=i+1)
					printf("%d ",g[r][i]);
				return 0;
			}
		}
	printf("NO");
	return 0;
}
/*
5 9
..#####..
#########
#.#####.#
#.......#
#########
*/