#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main() {
	scanf("%d%d%d",&a,&b,&c);
	if (c==0) printf("%s\n",a==b ? "YES" : "NO");
	else if (c>0) printf("%s\n",(b>=a && (b-a)%c==0) ? "YES" : "NO");
	else printf("%s\n",(b<=a && (a-b)%-c==0) ? "YES" : "NO");

	return 0;
}