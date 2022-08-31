//CF1450F
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
const int N = 111111;
int n,m,a[N],b[N];
int main()
{
	int T,i,j,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i=i+1)
			scanf("%d",a+i);
		m=1;
		b[a[1]]++,b[a[n]]++;
		for(i=1;i<n;i=i+1)
			if(a[i]==a[i+1])
				b[a[i]]+=2,m++;
		j=0;
		for(i=1;i<=n;i=i+1)
			if(b[j]<b[i])
				j=i;
		x=0;
		for(i=1;i<n;i=i+1)
			if(a[i]!=a[i+1]&&a[i]!=j&&a[i+1]!=j)
				x++;
		while(x&&b[j]>m+1){
			x--;
			m++;
		}
		if(b[j]>m+1)
			cout<<-1<<endl;
		else
			cout<<m-1<<endl;
		for(i=1;i<=n;i=i+1)
			a[i]=0,b[i]=0;
	}
	return 0;
}