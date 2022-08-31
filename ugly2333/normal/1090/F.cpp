//CF1090F
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
const int N = 1111;
LL f(int x,int y,int z){
	cout<<"? "<<x<<' '<<y<<' '<<z<<endl;
	cin>>x;
	return x;
}
LL g(int x,int y,int z,int w){
	LL p,q,r,s;
	p=f(x,y,z);
	q=f(x,y,w);
	r=f(x,w,z);
	s=f(w,y,z);
	return min(min(p,q),min(r,s))+max(max(p,q),max(r,s));
}
int n;
LL a[N];
int main()
{
	int i;
	LL p,q,r,s,t,o;
	cin>>n;
	p=g(1,2,3,4);
	q=g(1,2,3,5);
	r=g(1,2,5,4);
	s=g(1,5,3,4);
	t=g(5,2,3,4);
	o=(p+q+r+s+t)/4;
	a[5]=o-p;
	a[4]=o-q;
	a[3]=o-r;
	a[2]=o-s;
	a[1]=o-t;
	for(i=6;i<=n;i=i+1)
		a[i]=g(1,2,3,i)-a[1]-a[2]-a[3];
	cout<<'!';
	for(i=1;i<=n;i=i+1)
		cout<<' '<<a[i];
	cout<<endl;
	return 0;
}