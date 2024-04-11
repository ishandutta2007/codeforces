//CF 17C
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
const int N = 160;
const int M = 60;
const int mod = 51123987;
int ok(int x,int y){
	return max(x-y,y-x)<=1;
}
int n,m=59;
char s[N];
struct node{
	int x[M][M][M];
	node(int xx=1){
		ini(xx);
	}
	void ini(int xx){
		memset(x,0,sizeof(x));
		x[0][0][0]=xx;
	}
	int cnt(){
		int i,j,k,o=0;
		for(i=0;i<=m;i=i+1)
			for(j=0;j<=m;j=j+1){
				k=n-i-j;
				if(k>=0&&ok(i,j)&&ok(i,k)&&ok(j,k))
					o=(o+x[i][j][k])%mod;
			}
		ini(0);
		return o;
	}
}ab,ac,ba,bc,ca,cb,d,e;
node operator +(node& q,node& r){
	int i,j,k;
	node z;
	for(i=0;i<=m;i=i+1)
		for(j=0;j<=m;j=j+1)
			for(k=0;k<=m;k=k+1)
				z.x[i][j][k]=(q.x[i][j][k]+r.x[i][j][k])%mod;
	return z;
}
int main()
{
	int i,j,k,l,o=0;
	scanf("%d%s",&n,s+1);
	m=n/3+5;
	for(l=1;l<=n;l=l+1){
		e.ini(0);
		if(s[l]=='a'){
			d=ba+ca;
			for(i=1;i<=m;i=i+1)
				for(j=0;j<=m;j=j+1)
					for(k=0;k<=m;k=k+1)
						d.x[i][j][k]=(d.x[i][j][k]+d.x[i-1][j][k])%mod,e.x[i][j][k]=d.x[i-1][j][k];
			o=(o+ba.cnt())%mod;
			o=(o+ca.cnt())%mod;
			ab=ab+e;
			ac=ac+e;
		}
		if(s[l]=='b'){
			d=ab+cb;
			for(i=0;i<=m;i=i+1)
				for(j=1;j<=m;j=j+1)
					for(k=0;k<=m;k=k+1)
						d.x[i][j][k]=(d.x[i][j][k]+d.x[i][j-1][k])%mod,e.x[i][j][k]=d.x[i][j-1][k];
			o=(o+ab.cnt())%mod;
			o=(o+cb.cnt())%mod;
			ba=ba+e;
			bc=bc+e;
		}
		if(s[l]=='c'){
			d=ac+bc;
			for(i=0;i<=m;i=i+1)
				for(j=0;j<=m;j=j+1)
					for(k=1;k<=m;k=k+1)
						d.x[i][j][k]=(d.x[i][j][k]+d.x[i][j][k-1])%mod,e.x[i][j][k]=d.x[i][j][k-1];
			o=(o+ac.cnt())%mod;
			o=(o+bc.cnt())%mod;
			ca=ca+e;
			cb=cb+e;
		}
		//cout<<o<<endl;
	}
	o=(o+ab.cnt())%mod;
	o=(o+ac.cnt())%mod;
	o=(o+ba.cnt())%mod;
	o=(o+bc.cnt())%mod;
	o=(o+ca.cnt())%mod;
	o=(o+cb.cnt())%mod;
	//cout<<o<<endl;
	while(o%4){
		o+=mod;
	}
	cout<<o/4<<endl;
	return 0;
}