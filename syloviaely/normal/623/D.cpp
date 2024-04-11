#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000000;
double A[200],p[200];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); p[i]=k1/100.0;
	}
//	n=100; for (int i=1;i<=n;i++) p[i]=0.01;
	for (int i=1;i<=n;i++) A[i]=1;
	double ans=0;
	for (int now=1;now<=N;now++){
		double k1=1;
		for (int i=1;i<=n;i++) k1*=(1-A[i]);// cout<<now<<" "<<k1<<endl;
		ans+=1-k1; int where=0; double k2=0;
		if (now<=n) where=now;
		else for (int i=1;i<=n;i++)
			if (k1/(1-A[i])*(1-A[i]*(1-p[i]))>k2){
				where=i; k2=k1/(1-A[i])*(1-A[i]*(1-p[i]));
			}
		A[where]*=(1-p[where]);
	}
	printf("%.11lf\n",ans);
	return 0;
}