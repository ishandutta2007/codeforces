//CF1149B
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
const int N = 111111;
const int M = 255;
void cmin(int&x,int y){
	if(x>y)
		x=y;
}
char c[N],r[M];
int n,q,a[N],b[N][26],d[5][M],l[5],f[M][M][M];
void upd(int i,int j,int k){
	int x=n+1;
	if(i)
		cmin(x,b[f[i-1][j][k]+1][d[1][i]]);
	if(j)
		cmin(x,b[f[i][j-1][k]+1][d[2][j]]);
	if(k)
		cmin(x,b[f[i][j][k-1]+1][d[3][k]]);
	f[i][j][k]=x;
	//cout<<i<<j<<k<<f[i][j][k]<<endl;
}
int main()
{
	int i,j,k,o;
	scanf("%d%d%s",&n,&q,c+1);
	for(j=0;j<26;j=j+1)
		b[n+1][j]=n+1,b[n+2][j]=n+1;
	for(i=n;i;i=i-1){
		for(j=0;j<26;j=j+1)
			b[i][j]=b[i+1][j];
		b[i][c[i]-'a']=i;
	}
	f[0][0][0]=0;
	while(q--){
		scanf("%s%d",r,&o);
		if(r[0]=='-'){
			l[o]--;
			if(f[l[1]][l[2]][l[3]]<=n)
				cout<<"YES\n";
			else
				cout<<"NO\n";
			continue;
		}
		scanf("%s",r);
		l[o]++;
		d[o][l[o]]=r[0]-'a';
		if(o==1){
			i=l[1];
			for(j=0;j<=l[2];j=j+1)
				for(k=0;k<=l[3];k=k+1)
					upd(i,j,k);
		}
		if(o==2){
			j=l[2];
			for(i=0;i<=l[1];i=i+1)
				for(k=0;k<=l[3];k=k+1)
					upd(i,j,k);
		}
		if(o==3){
			k=l[3];
			for(i=0;i<=l[1];i=i+1)
				for(j=0;j<=l[2];j=j+1)
					upd(i,j,k);
		}
		//cout<<f[l[1]][l[2]][l[3]];
		if(f[l[1]][l[2]][l[3]]<=n)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}