#include <bits/stdc++.h>
using namespace std;
int w1,w2,h1,h2;
int main()
{
	scanf("%d%d%d%d",&w1,&h1,&w2,&h2);
	printf("%lld",(max(w1,w2)+2)*(long long)(2+h1+h2)-(max(w1,w2))*(long long)(h1+h2));
	return 0;
}