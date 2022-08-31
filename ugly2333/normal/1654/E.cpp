//CF1654E
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
const int B = 333;
int n,m,a[N],b[N];
int main()
{
	int i,j,k,x,s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	s=1;
	for(k=-B;k<=B;k++){
		for(i=1;i<=n;i++)
			b[i]=a[i]-i*k;
		sort(b+1,b+n+1);
		x=1;
		for(i=2;i<=n+1;i++){
			if(i==n+1||b[i]!=b[i-1]){
				s=max(s,x);
				x=1;
			}
			else
				x++;
		}
	}
	for(i=1;i<=n;i++){
		m=0;
		for(j=i+1;j<=i+B&&j<=n;j++){
			if((a[j]-a[i])%(j-i)==0)
				b[++m]=(a[j]-a[i])/(j-i);
		}
		sort(b+1,b+m+1);
		x=1;
		for(j=2;j<=m+1;j++){
			if(j==m+1||b[j]!=b[j-1]){
				s=max(s,x+1);
				x=1;
			}
			else
				x++;
		}
	}
	printf("%d\n",n-s);
	return 0;
}