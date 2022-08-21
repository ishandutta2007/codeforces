#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
long long l,r,k;
int main()
{
	cin>>l>>r>>k; bool ok=0;
	for(long long x=1,lst=0;(x/k)==lst;lst=x,x*=k)
	{
		if(l<=x&&x<=r) cout<<x<<" ",ok=1;
	}
	if(!ok) printf("-1\n");
}