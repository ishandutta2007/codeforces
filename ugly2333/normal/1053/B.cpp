//CF1053B
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
int n,a[N],b[2],l[N][66],r[N][66];
int main()
{
	int i,j;
	LL x,y,s=0;
	scanf("%d",&n);
	b[0]++;
	for(i=1;i<=n;i=i+1){
		scanf("%I64d",&x);
		y=0;
		while(x){
			y+=x&1;
			x>>=1;
		}
		a[i]=y;
		s^=y;
		b[s&1]++;
	}
	s=(LL)b[0]*(b[0]-1)+(LL)b[1]*(b[1]-1);
	s/=2;
	for(i=1;i<=n;i=i+1){
		for(j=a[i-1];j<=64;j=j+1)
			l[i][j]=l[i-1][j-a[i-1]];
		l[i][0]++;
	}
	for(i=n;i;i=i-1){
		for(j=a[i+1];j<=64;j=j+1)
			r[i][j]=r[i+1][j-a[i+1]];
		r[i][0]++;
	}
	for(i=1;i<=n;i=i+1){
		for(j=2;j<=64;j=j+1)
			l[i][j]+=l[i][j-2];
		for(j=0;j<a[i];j=j+1){
			s-=(LL)r[i][j]*l[i][a[i]-2-j];
		}
	}
	cout<<s;
	return 0;
}