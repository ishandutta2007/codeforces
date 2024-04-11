#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=1005;
int T,n,m;
int a[maxn][maxn],b[maxn][maxn],c[3],d[3],e[3];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]),a[i][j]--;
		cin>>s,c[0]=0,c[1]=1,c[2]=2,d[0]=d[1]=d[2]=0;
		for(int i=0;i<m;i++){
			if(s[i]=='U')
				d[0]--;
			if(s[i]=='D')
				d[0]++;
			if(s[i]=='L')
				d[1]--;
			if(s[i]=='R')
				d[1]++;
			if(s[i]=='I')
				swap(c[1],c[2]),swap(d[1],d[2]);
			if(s[i]=='C')
				swap(c[0],c[2]),swap(d[0],d[2]);
		}
		d[0]=(d[0]%n+n)%n,d[1]=(d[1]%n+n)%n,d[2]=(d[2]%n+n)%n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				e[0]=i,e[1]=j,e[2]=a[i][j],b[(e[c[0]]+d[0])%n][(e[c[1]]+d[1])%n]=(e[c[2]]+d[2])%n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				printf("%d%c",b[i][j]+1,j==n-1? '\n':' ');
	}
	return 0;
}