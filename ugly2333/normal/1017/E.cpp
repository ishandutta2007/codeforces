//CF 1017E
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
const int N = 444444;
const DB eps = 1e-9;
int n,m;
LL x[N],y[N];
LL dis2(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
DB dis(int i,int j){
	return sqrt((DB)dis2(i,j));
}
LL chk(int i,int j,int k){
	return (y[j]-y[i])*(x[k]-x[j])-(y[k]-y[j])*(x[j]-x[i]);
}
DB cal(int i,int j,int k){
	return (DB)(dis2(i,j)+dis2(j,k)-dis2(i,k))/(2.0*dis(i,j)*dis(j,k));
}
int sc,c[N],sd,d[N];
vector<int> v1,v2;
DB q1[N],q2[N];
pair<LL,int> p[N];
int main()
{
	int i,j,xx,yy;
	DB t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n+m;i=i+1)
		scanf("%d%d",&xx,&yy),x[i]=xx,y[i]=yy;
	
	for(i=1;i<=n;i=i+1)
		p[i]=make_pair((LL)x[i]<<32|y[i],i);
	sort(p+1,p+n+1);
	sc=0,sd=0;
	for(i=1;i<=n;i=i+1){
		j=p[i].second;
		while(sc>=2&&chk(c[sc-1],c[sc],j)<=0){
			c[sc--]=0;
		}
		c[++sc]=j;
		while(sd>=2&&chk(d[sd-1],d[sd],j)>=0){
			d[sd--]=0;
		}
		d[++sd]=j;
	}
	for(i=1;i<sc;i=i+1)
		v1.push_back(c[i]);
	for(i=sd;i>1;i=i-1)
		v1.push_back(d[i]);
	
	for(i=n+1;i<=n+m;i=i+1)
		p[i-n]=make_pair((LL)x[i]<<32|y[i],i);
	sort(p+1,p+m+1);
	sc=0,sd=0;
	for(i=1;i<=m;i=i+1){
		j=p[i].second;
		while(sc>=2&&chk(c[sc-1],c[sc],j)<=0){
			c[sc--]=0;
		}
		c[++sc]=j;
		while(sd>=2&&chk(d[sd-1],d[sd],j)>=0){
			d[sd--]=0;
		}
		d[++sd]=j;
	}
	for(i=1;i<sc;i=i+1)
		v2.push_back(c[i]);
	for(i=sd;i>1;i=i-1)
		v2.push_back(d[i]);
	
	if(v1.size()!=v2.size()){
		cout<<"NO";
		return 0;
	}
	n=v1.size();
	v1.push_back(v1[0]),v2.push_back(v2[0]);
	v1.push_back(v1[1]),v2.push_back(v2[1]);
	for(i=0;i<n;i=i+1)
		q1[i<<1]=cal(v1[i],v1[i+1],v1[i+2]),q1[i<<1|1]=dis(v1[i+1],v1[i+2]);
	for(i=0;i<n;i=i+1)
		q2[i<<1]=cal(v2[i],v2[i+1],v2[i+2]),q2[i<<1|1]=dis(v2[i+1],v2[i+2]),q2[i+i+n+n]=q2[i<<1],q2[i+i+n+n+1]=q2[i<<1|1];
	n<<=1;
	for(i=0;i<n;i=i+1){
		for(j=0;j<n;j=j+1){
			t=q2[i+j]-q1[j];
			if(t<-eps||eps<t)
				break;
		}
		if(j==n){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}