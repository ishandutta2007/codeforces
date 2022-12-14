#include <iostream>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 300000
char str[max_n+2],buf[max_n+2];
il void test(){
	scanf("\n%s",str+1);
	int n=strlen(str+1),now=0;
	for(int i=1; i<=n; ++i)
		if(str[i]=='A')
			buf[++now]='A';
		else
			if(now)
				--now;
			else
				buf[now=1]='B';
	printf("%d\n",now);
//	buf[now+1]='\0';
//	printf("%s\n",buf+1);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}