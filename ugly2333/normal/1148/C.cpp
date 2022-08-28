//CF1148C
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
const int N = 333333;
int n,m,a[N],b[N];
vector<int> v1,v2;
void go(int x,int y){
	v1.push_back(x);
	v2.push_back(y);
	swap(a[x],a[y]);
	b[a[x]]=x,b[a[y]]=y;
}
int main()
{
	int i;
	scanf("%d",&n);
	m=n/2;
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),b[a[i]]=i;
	for(i=m;i>=2;i=i-1){
		if(b[i]==i)
			continue;
		if(b[i]>m)
			go(1,b[i]);
		if(b[i]<=m)
			go(b[i],n);
		go(i,n);
	}
	for(i=m+1;i<n;i=i+1){
		if(b[i]==i)
			continue;
		if(b[i]<=m)
			go(b[i],n);
		if(b[i]>m)
			go(1,b[i]);
		go(1,i);
	}
	if(a[1]!=1)
		go(1,n);
	cout<<v1.size()<<endl;
	for(i=0;i<v1.size();i=i+1)
		cout<<v1[i]<<' '<<v2[i]<<endl;
	return 0;
}