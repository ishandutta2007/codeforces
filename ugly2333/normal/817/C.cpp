// CF 817C
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
LL cal(LL x)
{
	LL y;
	y=x;
	int t;
	t=0;
	while(x>0){
		t+=x%10;
		x/=10;
	}
	return (LL)y-t;
}
int main()
{
	LL n,s,l,r,m;
	cin>>n>>s;
	l=1;
	r=n+1;
	while(l<r){
		m=(l+r)/(LL)2;
		if(cal(m)<s)
			l=m+1;
		else
			r=m;
	}
	l--;
	n-=(LL)l;
	cout<<n<<endl;
	return 0;
}