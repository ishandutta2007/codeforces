#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,b,p;
int gx(int x)
{
	if(x==1) return 0;
	int gg=1;
	while(gg<=x) gg<<=1;
	gg>>=1;
	return b*gg+gg/2+gx(x-gg/2);
}
int main()
{
	cin>>n>>b>>p;
	cout<<gx(n)<<" "<<p*n;
}