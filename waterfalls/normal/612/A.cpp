#include <bits/stdc++.h>
using namespace std;

int n,p,q;
char buff[113];
string s;

int main() {
	scanf("%d%d%d %s",&n,&p,&q,&buff);
	s = string(buff);
	for (int a=0;a<113;a++) for (int b=0;b<113;b++) {
		if (a*p+b*q==n) {
			printf("%d\n",a+b);
			int on = 0;
			for (int i=0;i<a;i++) {
				printf("%s\n",s.substr(on,p).c_str());
				on+=p;
			}
			for (int i=0;i<b;i++) {
				printf("%s\n",s.substr(on,q).c_str());
				on+=q;
			}
			exit(0);
		}
	}
	printf("-1\n");

	return 0;
}