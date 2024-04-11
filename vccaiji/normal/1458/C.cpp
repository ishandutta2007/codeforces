#include<bits/stdc++.h>//luogu
using namespace std;
int t,n,m;
int a[1100][1100];
int b[1100][1100];
int d[3];
int e[3];
char s[110000];
int main(){
	scanf("%d",&t);
	while(t--){
		d[0]=d[1]=d[2]=0;
		e[0]=0;
		e[1]=1;
		e[2]=2;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) a[i][j]--;
		scanf("%s",s);
		for(int i=0;i<m;i++){
			if(s[i]=='U')
				d[0]=(d[0]+n-1)%n;
			if(s[i]=='D')
			    d[0]=(d[0]+1)%n;
			if(s[i]=='L')
			    d[1]=(d[1]+n-1)%n;
			if(s[i]=='R')
			    d[1]=(d[1]+1)%n;
			if(s[i]=='I'){
				swap(d[1],d[2]);
				swap(e[1],e[2]);
			}
			if(s[i]=='C'){
				swap(d[0],d[2]);
				swap(e[0],e[2]);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int x[3],y[3];
				x[0]=i;
				x[1]=j;
				x[2]=a[i][j];
				for(int k=0;k<3;k++) y[k]=(x[e[k]]+d[k])%n;
				b[y[0]][y[1]]=y[2]+1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) printf("%d ",b[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}