#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
char p[1000001];
int main()
{
	cin>>p; bool ok=0;
	for(int i=0;p[i];++i)
	{
		int q=i;
		if(p[q]!=p[q+1]) continue;
		q++;
		if(p[q]!=p[q+1]) continue;
		q++;
		if(p[q]!=p[q+1]) continue;
		q++;
		if(p[q]!=p[q+1]) continue;
		q++;
		if(p[q]!=p[q+1]) continue;
		q++;
		if(p[q]!=p[q+1]) continue;
		ok=1;
	}
	if(ok) cout<<"YES"; else cout<<"NO";
}