//CF1148E
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
const int inf = 1e9+N;
int n,a[N],b[N],c[N];
pair<int,int> p[N];
vector<int> v1,v2,v3;
void go(int i,int j,int d){
	v1.push_back(i);
	v2.push_back(j);
	v3.push_back(d);
}
int main()
{
	int i,j,x;
	LL o;
	scanf("%d",&n);
	o=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		p[i]=make_pair(a[i],i);
		o+=a[i];
	}
	for(i=1;i<=n;i=i+1){
		scanf("%d",b+i);
		o-=b[i];
	}
	if(o){
		cout<<"NO";
		return 0;
	}
	sort(p+1,p+n+1);
	sort(b+1,b+n+1);
	for(i=1;i<=n;i=i+1)
		c[i]=b[i]-p[i].first;
	j=1;
	for(i=1;i<=n;i=i+1){
		if(c[i]>=0)
			continue;
		while(j<i&&c[i]<0){
			if(!c[j])
				j++;
			x=min(-c[i],c[j]);
			go(p[j].second,p[i].second,x);
			c[i]+=x;
			c[j]-=x;
		}
		if(c[i]<0){
			cout<<"NO";
			return 0;
		}
	}
	printf("YES\n%d\n",v1.size());
	for(i=0;i<v1.size();i=i+1)
		printf("%d %d %d\n",v1[i],v2[i],v3[i]);
	return 0;
}