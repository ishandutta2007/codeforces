#include<bits/stdc++.h>
using namespace std;
const int max_n=350+5;
int b[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",b+i);
	for(int r=1;r<=n;++r)
		for(int c=1;c<=n;++c)
			printf("%d%c",(b[r]+(c-r+n)*r)%n," \n"[c==n]);
	return 0;
}