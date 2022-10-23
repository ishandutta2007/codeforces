#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%i",&n);
	int zero=0;
	int one=1023;
	for(int i=1;i<=n;i++){
		char t;
		int x;
		scanf("\n%c %i",&t,&x);
		if(t=='|'){
			zero|=x;
			one|=x;
		}else if(t=='&'){
			zero&=x;
			one&=x;
		}else{
			zero^=x;
			one^=x;
		}
	}
	int x=0,o=0,a=1023;
	for(int i=0;i<10;i++){
		int p=zero>>i&1,q=one>>i&1;
		if(p&&q)o|=1<<i;
		else if(p&&!q)x|=1<<i;
		else if(!p&&!q)a^=1<<i;
	}
	printf("3\n");
	printf("^ %i\n",x);
	printf("& %i\n",a);
	printf("| %i\n",o);
	return 0;
}