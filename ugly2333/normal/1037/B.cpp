//CF 1037B
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
int a[222222];
int main()
{
	int n,k,i,t;
	LL s=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	t=n/2+1;
	if(a[t]<k){
		for(i=t;i<=n;i=i+1)
			if(a[i]<k)
				s+=k-a[i];
	}
	else{
		for(i=t;i;i=i-1)
			if(a[i]>k)
				s+=a[i]-k;
	}
	cout<<s;
	return 0;
}