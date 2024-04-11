//CF 711E
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
typedef double DB;
const int P = 1e6+3;
const int W = 1e6+2;
int fpow(int x,LL y){
	if(!y)
		return 1;
	LL z=fpow(x,y>>1);
	z=z*z%P;
	if(y&1)
		z=z*x%P;
	return z;
}
int main()
{
	LL n,k,a,b,c,x,s;
	int i;
	cin>>n>>k;
	if(n<=61&&k>((LL)1<<n)){
		cout<<1<<' '<<1;
		return 0;
	}
	if(k>=P)
		a=0;
	else{
		a=1;
		x=fpow(2,n%W);
		for(i=1;i<=k;i=i+1){
			a=a*x%P;
			x--;
			if(x<0)
				break;
		}
	}
	b=fpow(2,n%W);
	b=fpow(b,k%W);
	s=n%W;
	for(i=1;i<=61;i=i+1){
		s+=(k-1)>>i;
		s%=W;
	}
	c=fpow(2,s);
	c=fpow(c,P-2);
	a=b-a;
	if(a<0)
		a+=P;
	a=a*c%P;
	b=b*c%P;
	cout<<a<<' '<<b;
	return 0;
}