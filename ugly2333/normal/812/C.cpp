// CF 812C
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
int n,a[111111];
LL S,b[111111];
int ok(int m)
{
	int i;
	LL s;
	for(i=1;i<=n;i=i+1)
		b[i]=(LL)m*i+a[i];
	sort(b+1,b+n+1);
	s=0;
	for(i=1;i<=m;i=i+1)
		s+=b[i];
	if(s<=S)
		return s;
	return 0;
}
int main()
{
	int i,l,r,m;
	cin>>n>>S;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	l=0;
	r=n;
	while(l<r){
		m=(l+r+1)/2;
		if(ok(m))
			l=m;
		else
			r=m-1;
	}
	cout<<l<<' '<<ok(l)<<endl;
	return 0;
}