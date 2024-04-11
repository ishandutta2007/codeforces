#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int m,n;
	scanf("%d%d",&n,&m);
	if (m>(n+1)*2||n>m+1) return printf("-1"),0;
	int one=0;
	while (n>0||m>0)
	{
		if (n>m||one==2)
		{
			cout<<"0";
			--n;
			one=0;
		} else {
			cout<<"1";
			--m;
			++one;
		}
	}
	puts("");
	return 0;
}