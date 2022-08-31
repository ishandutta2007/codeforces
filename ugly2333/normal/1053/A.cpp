//CF1053A
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
	int n,m,k,x,nn,mm;
	LL s;
	cin>>n>>m>>k;
	nn=n,mm=m;
	s=(LL)2*n*m;
	if(s%k){
		cout<<"NO";
		return 0;
	}
	s/=k;
	x=gcd(n,k);
	n/=x,k/=x;
	x=gcd(m,k);
	m/=x,k/=x;
	if(k==1){
		if(n<nn)
			n*=2;
		else
			m*=2;
	}
	cout<<"YES\n";
	cout<<0<<' '<<0<<endl;
	cout<<n<<' '<<0<<endl;
	cout<<0<<' '<<m<<endl;
	return 0;
}