//CF1427E
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
const int N = 11111;
int n=1500,b[N];
LL x,a[N];
vector<LL> v1,v2,v3;
void ans(LL x,LL y,int o){
	v1.push_back(x);
	v2.push_back(y);
	v3.push_back(o);
}
int main()
{
	int i,k;
	LL j;
	cin>>x;
	a[1]=x;
	ans(x,x,1);
	x*=2;
	for(i=2;i<=n;i=i+1){
		ans(x,a[i-1],1);
		a[i]=x+a[i-1];
	}
	for(i=n+1;i<=n+n;i=i+1){
		k=rand()%n+1;
		ans(a[k],a[i-1],1);
		a[i]=a[k]+a[i-1];
	}
	for(i=n+n+1;i<=n+n+n;i=i+1){
		k=rand()%(n+n)+1;
		ans(a[k],a[i-1],1);
		a[i]=a[k]+a[i-1];
	}
	n*=3;
	for(j=(LL)1<<62;j;j>>=1){
		k=0;
		for(i=1;i<=n;i=i+1)
			if((!b[i])&&(a[i]&j))
				k=i;
		if(!k)
			continue;
		b[k]=1;//cout<<j<<' '<<k<<endl;
		for(i=1;i<=n;i=i+1)
			if(i!=k&&(a[i]&j))
				ans(a[k],a[i],2),a[i]^=a[k];
	}
	cout<<min(100000,(int)v1.size())<<endl;
	for(i=0;i<min(100000,(int)v1.size());i=i+1){
		cout<<v1[i];
		if(v3[i]==1)
			cout<<" + ";
		else
			cout<<" ^ ";
		cout<<v2[i]<<endl;
		/*if(v3[i]==2&&(v1[i]^v2[i])==1)
			return 1;*/
	}
	return 0;
}