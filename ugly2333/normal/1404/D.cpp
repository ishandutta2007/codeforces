//CF1404D
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
const int N = 1111111;
int n,a[N],b[N],c[N],d[N];
int F(int x){
	if(x<=n)
		return x+n;
	return x-n;
}
int main()
{
	int i,j,x;
	LL s;
	scanf("%d",&n);
	if(n&1){
		cout<<"Second"<<endl;
		for(i=1;i<=n*2;i=i+1)
			scanf("%d",a+i),c[a[i]]=b[a[i]],b[a[i]]=i;
		for(i=1;i<=n;i=i+1){
			if(!d[i]){
				d[i]=b[i];
				for(j=F(c[i]);j!=b[i];){
					x=a[j];
					d[x]=j;
					j=F(b[x]^c[x]^j);
				}
			}
		}
		s=0;
		for(i=1;i<=n;i=i+1)
			s+=d[i];
		s/=n;
		if(s&1){
			for(i=1;i<=n;i=i+1)
				printf("%d ",b[i]^c[i]^d[i]);
		}
		else{
			for(i=1;i<=n;i=i+1)
				printf("%d ",d[i]);
		}
		cout<<endl;
	}
	else{
		cout<<"First"<<endl;
		for(i=1;i<=n*2;i=i+1)
			printf("%d ",min(i,F(i)));
		cout<<endl;
	}
	return 0;
}