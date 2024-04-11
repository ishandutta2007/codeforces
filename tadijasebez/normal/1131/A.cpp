#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h1,w1,h2,w2;
	scanf("%i %i %i %i",&w1,&h1,&w2,&h2);
	int ans=w1+w2+4+abs(w1-w2)+(h1+h2)*2;
	printf("%i\n",ans);
	return 0;
}