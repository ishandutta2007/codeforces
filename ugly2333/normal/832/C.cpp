//CF 832C
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
const int m = 1e6;
const double eps = 1e-9;
int n,V,nl,nr,a[m+111],b[m+111];
vector<pair<int,int> > L,R;
void geta(double t)
{
	int i,x,y;
	double z,p;
	for(i=0;i<nl;i=i+1){
		x=L[i].first;
		y=L[i].second;
		z=x;
		if(z/y<=t){
			a[0]++;
			a[m+1]--;
			continue;
		}
		if(z/(V+y)>t)
			continue;
		z-=t*y;
		p=z/V;
		p=t-p;
		z=p*(V-y);
		a[x]++;
		x+=(int)z;
		a[min(m,x)+1]--;
	}
}
void getb(double t)
{
	int i,x,y;
	double z,p;
	for(i=0;i<nr;i=i+1){
		x=R[i].first;
		y=R[i].second;
		z=m-x;
		if(z/y<=t){
			b[0]++;
			b[m+1]--;
			continue;
		}
		if(z/(V+y)>t)
			continue;
		z-=t*y;
		p=z/V;
		p=t-p;
		z=p*(V-y);
		b[x+1]--;
		x-=(int)z;
		b[max(0,x)]++;
	}
}
bool ok(double t)
{
	int i;
	for(i=0;i<=m;i=i+1){
		a[i]=0;
		b[i]=0;
	}
	geta(t);
	getb(t);
	for(i=1;i<=m;i=i+1){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	for(i=0;i<=m;i=i+1)
		if(a[i]&&b[i])
			return 1;
	return 0;
}
int main()
{
	int i,x,y,z;
	double l,r,md;
	scanf("%d%d",&n,&V);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		if(z==1){
			nl++;
			L.push_back(make_pair(x,y));
		}
		else{
			nr++;;
			R.push_back(make_pair(x,y));
		}
	}
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	l=0;
	r=m;
	while(r-l>eps){
		md=(l+r)/2;
		if(ok(md))
			r=md;
		else
			l=md;
	}
	printf("%.9lf",md);
	return 0;
}