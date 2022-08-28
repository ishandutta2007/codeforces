//CF 911D
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
const int N = 1555;
int n,m,a[N],c[N];
int main()
{
	int i,j,x,y,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		for(j=1;j<i;j=j+1)
			if(a[j]>a[i])
				s^=1;
		c[i]=c[i-1]^(i&1)^1;
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&x,&y);
		i=y-x+1;
		s^=c[i];
		if(!s)
			cout<<"even\n";
		else
			cout<<"odd\n";
	}
	return 0;
}