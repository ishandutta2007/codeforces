//CF1427D
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
const int N = 111;
int n,a[N],b[N],c[N],d[N];
void go(){
	int m,i,x;//for(i=1;i<=n;i=i+1)cout<<a[i]<<b[i]<<endl;cout<<endl;
	for(i=1;i<=n;i=i+1)
		c[i]=a[i],d[i]=0;
	for(i=1;i<=n;i=i+1){
		if(i<n&&c[i+1]==c[i]+1)
			c[i]=0;
		else
			d[c[i]]=1;
	}
	m=0;
	for(i=1;i<=n;i=i+1)
		if(d[i])
			d[i]=++m;
	m=0;
	for(i=1;i<=n;i=i+1){
		if(c[i]){
			m++;
			a[m]=d[c[i]];
			b[m]=b[i];
		}
	}
	n=m;//for(i=1;i<=n;i=i+1)cout<<a[i]<<b[i]<<endl;cout<<endl;
}
int nn,sz;
vector<int> v[N];
void ans(int v1,int v2,int v3){
	if(v1)
		v[sz].push_back(v1);
	if(v2-v1)
		v[sz].push_back(v2-v1);
	if(v3-v2)
		v[sz].push_back(v3-v2);
	if(nn-v3)
		v[sz].push_back(nn-v3);
	sz++;
}
int main()
{
	int i,j,k,m,f;
	scanf("%d",&n);
	nn=n;
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),b[i]=i;
	go();
	while(n>1){
		f=0;
		for(i=1;i<=n;i=i+1){
			for(j=i+1;j<=n;j=j+1){
				if(a[i]==a[j]+1)
					ans(b[i-1],b[j-1],b[j]),f=1;
				if(f)
					break;
			}
			if(f)
				break;
		}
		//cout<<n<<i<<j<<endl;
		for(k=n;k>=2;k=k-1)
			b[k]-=b[k-1];
		m=0;
		for(k=j+1;k<=n;k=k+1)
			m++,c[m]=a[k],d[m]=b[k];
		m++,c[m]=a[j],d[m]=b[j];
		for(k=i;k<j;k=k+1)
			m++,c[m]=a[k],d[m]=b[k];
		for(k=1;k<i;k=k+1)
			m++,c[m]=a[k],d[m]=b[k];
		for(k=1;k<=n;k=k+1)
			a[k]=c[k],b[k]=d[k];
		for(k=2;k<=n;k=k+1)
			b[k]+=b[k-1];
		go();
	}
	cout<<sz<<endl;
	for(i=0;i<sz;i=i+1){
		cout<<v[i].size();
		for(j=0;j<v[i].size();j=j+1)
			cout<<' '<<v[i][j];
		cout<<endl;
	}
	return 0;
}