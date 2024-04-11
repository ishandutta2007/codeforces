//CF1142A
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
LL gcd(LL x,LL y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int main()
{
	int n,k,a,b;
	LL s,o,x,y,i;
	cin>>n>>k>>a>>b;
	if(a>b)
		swap(a,b);
	s=(LL)n*k;
	x=0,y=s+1;
	for(i=k-a-b;i<=s;i=i+k){
		o=gcd(s,i);
		x=max(x,o);
		y=min(y,o);
	}
	for(i=b-a;i<=s;i=i+k){
		o=gcd(s,i);
		x=max(x,o);
		y=min(y,o);
	}
	cout<<s/x<<' '<<s/y<<endl;
	return 0;
}