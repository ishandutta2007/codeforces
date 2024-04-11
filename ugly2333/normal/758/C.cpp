#include<iostream>
#include<cstdio>
using namespace std;
int a[122][122];
int main()
{
	int n,m,x,y,r,l,i,j;
	long long k,ma,mi,mm,p;
	cin>>n>>m>>k>>x>>y;
	if(n==1){
		mi=k/m;
		if(k%m!=0)
			ma=mi+1;
		else
			ma=mi;
		if(k%m<y)
			mm=mi;
		else
			mm=ma;
		//cout<<k%m<<endl;
		cout<<ma<<' '<<mi<<' '<<mm<<endl;
		return 0;
	}
	r=2*(n-1)*m;
	p=k/r;
	l=k%r;
	if(l>=n*m)
		mi=p+1;
	else
		mi=p;
	if(n==2){
		ma=p;
		if(l>0)
			ma++;
	}
	else{
		ma=2*p;
		if(l>m||(p==0&&l>0))
			ma++;
		if(l>n*m)
			ma++;
	}
	for(i=1;i<=n&&l>0;i=i+1)
		for(j=1;j<=m&&l>0;j=j+1){
			a[i][j]++;
			l=l-1;
		}
	for(i=n-1;i>1&&l>0;i=i-1)
		for(j=1;j<=m&&l>0;j=j+1){
			a[i][j]++;
			l=l-1;
		}
	mm=a[x][y];
	if(x==1||x==n)
		mm+=p;
	else
		mm+=2*p;
	/*for(i=1;i<=n;i=i+1){
		for(j=1;j<=m;j=j+1){
			//cout<<a[i][j]<<endl;
			if(i==1||i==n)
				mi=min(mi,p+a[i][j]);
			else
				ma=max(ma,2*p+a[i][j]);
		}
	}*/
	cout<<ma<<' '<<mi<<' '<<mm<<endl;
	return 0;
}