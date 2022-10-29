#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[500005];
int qzh[500005];
int main(int argc, char** argv) {
	scanf("%s",a+1);
	a[0]=' ';
	int n=strlen(a)-1;
	qzh[0]=100000;
	for(int i=1;i<=n;i++)
		qzh[i]=min((int)a[i],qzh[i-1]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>qzh[i])
			puts("Ann");
		else
			puts("Mike");
	}
	return 0;
}