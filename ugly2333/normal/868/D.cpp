//CF 868D
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
const int N = 111;
const int K = 7;
const int P = 1<<K;
char c[111][111];
bool a[2*N][4*P][K+1];
int len[2*N];
int b[2*N][K+1],e[2*N][K+1];
int ch[N];
int ans[2*N];
int main()
{
	int n,m,i,j,x,y,k,p,t,l,lx,ly,h;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>c[i];
		l=strlen(c[i]);
		len[i]=l;
		for(k=1;k<=K;k=k+1){
			x=0;
			p=1<<k;
			for(j=0;j<l;j=j+1){
				x=x*2+c[i][j]-48;
				x=x&(p-1);
				if(j>=k-1)
					a[i][x][k]=1;
			}
			//cout<<x<<endl;
		}
		//cout<<endl;
		for(j=0;j<=K&&j<l;j=j+1)
			b[i][j]=c[i][j]-48;
		for(j=0;j<=K&&j<l;j=j+1)
			e[i][j]=c[i][l-j-1]-48;
	}
	cin>>m;
	for(i=n+1;i<=n+m;i=i+1){
		cin>>x>>y;
		lx=len[x];
		ly=len[y];
		if(lx>=10*K||ly>=10*K)
			l=max(lx,ly);
		else
			l=lx+ly;
		len[i]=l;
		t=0;
		for(j=min(lx-1,K);j>=0;j=j-1)
			ch[t++]=e[x][j];
		for(j=0;j<=K&&j<ly;j=j+1)
			ch[t++]=b[y][j];
		//for(j=0;j<t;j=j+1) cout<<ch[j];
		//cout<<endl;
		for(j=0;j<=K&&j<l;j=j+1){
			if(j<lx)
				b[i][j]=b[x][j];
			else
				b[i][j]=b[y][j-lx];
			if(j<ly)
				e[i][j]=e[y][j];
			else
				e[i][j]=e[x][j-ly];
		}
		
		for(k=1;k<=K;k=k+1){
			p=1<<k;
			for(j=0;j<p;j=j+1)
				a[i][j][k]=a[x][j][k]|a[y][j][k];
			h=0;
			for(j=0;j<t;j=j+1){
				h=h*2+ch[j];
				h=h&(p-1);
				if(j>=k-1)
					a[i][h][k]=1;
			}
			h=1;
			for(j=0;j<p;j=j+1)
				if(!a[i][j][k])
					h=0;
			if(h)
				ans[i]=k;
		}
		
		cout<<ans[i]<<endl;
	}
	//for(j=0;j<=6;j=j+1)
	//	cout<<len[j]<<endl;
	return 0;
}
/*

*/