//CF 800A
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
int a[111111],b[111111];
int main()
{
	int n,i;
	long long p,s;
	double l,m,r,ss;
	cin>>n>>p;
	s=0;
	for(i=1;i<=n;i=i+1){
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	if(s<=p){
		cout<<-1<<endl;
		return 0;
	}
	l=0.0;
	r=1e11+100;
	while(r-l>1e-8){
		m=(l+r)/2;
		ss=0.0;
		for(i=1;i<=n;i=i+1)
			if(m*a[i]>b[i])
				ss=ss+m*a[i]-b[i];
		if(ss<=m*p)
			l=m;
		else
			r=m;
	}
	printf("%.9f",l);
	return 0;
}