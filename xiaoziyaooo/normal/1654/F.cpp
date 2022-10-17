#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1<<18,maxk=20;
int n,m;
int val[maxn][maxk],rec[maxn][maxk];
string s;
struct node{
	int a,b;
	bool operator ==(const node &p)const{
		return (a==p.a&&b==p.b);
	}
	bool operator <(const node &p)const{
		return a<p.a||(a==p.a&&b<p.b);
	}
}va[maxn];
int main(){
	scanf("%d",&n),m=(1<<n),cin>>s;
	for(int i=0;i<m;i++)
		val[i][0]=s[i]-96,rec[i][0]=i^1;
	for(int i=1;i<=n;i++){
		//j 2^i
		for(int j=0;j<m;j++)
			rec[j][i]=rec[rec[j][i-1]][i-1]^(1<<i),va[j]=node{val[j][i-1],val[rec[j][i-1]][i-1]};
		sort(va,va+m);
		for(int j=0;j<m;j++)
			val[j][i]=lower_bound(va,va+m,node{val[j][i-1],val[rec[j][i-1]][i-1]})-va;
	}
	int res=0;
	for(int i=0;i<m;i++)
		if(val[i][n]<val[res][n])
			res=i;
	for(int i=0;i<m;i++)
		putchar(s[i^res]);
	return 0;
}