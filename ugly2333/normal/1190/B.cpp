//CF1190B
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
int n,a[N];
void go(){
	cout<<"cslnb";
	exit(0);
}
int main()
{
	int i,x,f;
	scanf("%d",&n);
	for(i=0;i<n;i=i+1)
		scanf("%d",a+i);
	sort(a,a+n);
	for(i=2;i<n;i=i+1)
		if(a[i]==a[i-1]&&a[i]==a[i-2])
			go();
	if(n>=2&&a[1]==0)
		go();
	x=0;
	for(i=1;i<n;i=i+1)
		if(a[i]==a[i-1])
			x++;
	if(x>=2)
		go();
	f=0;
	for(i=1;i<n;i=i+1)
		if(a[i]==a[i-1])
			a[i-1]--,f=1;
	for(i=1;i<n;i=i+1)
		if(a[i]==a[i-1])
			go();
	x=0;
	for(i=0;i<n;i=i+1)
		x+=a[i]-i;
	x&=1;
	if(f^x)
		cout<<"sjfnb";
	else
		cout<<"cslnb";
	return 0;
}