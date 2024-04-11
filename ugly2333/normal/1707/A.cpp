//CF1707A
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
int n,q,s,a[N],b[N],c[N];
int chk(int k){
	int i,x,t;
	x=q;
	t=0;
	for(i=1;i<=n;i++){
		if(x&&(x>=a[i]||i>=k)){
			t++;
			c[i]=1;
			if(x<a[i])
				x--;
		}
		else
			c[i]=0;
	}
	if(t>s){
		s=t;
		for(i=1;i<=n;i++)
			b[i]=c[i];
	}
	return x>0;
}
int main()
{
	int T,i,l,r,h;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		l=1,r=n+1;
		s=0;
		while(l<=r){
			h=l+r>>1;
			if(chk(h))
				r=h-1;
			else
				l=h+1;
		}
		for(i=1;i<=n;i++)
			printf("%d",b[i]);
		printf("\n");
	}
	return 0;
}