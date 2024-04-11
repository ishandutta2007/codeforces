#include <stdio.h>
#include <algorithm>
#include <string>
#include <memory.h>

char s[100];

int main(){
	gets(s);
	int x=0,y=0,a=0,b=0;
	for (int i=0;i<strlen(s);i++){
		if (s[i]!='0')x=x*10+s[i]-'0';
		a=a*10+s[i]-'0';
	}
	gets(s);
	for (int i=0;i<strlen(s);i++){
		if (s[i]!='0')y=y*10+s[i]-'0';
		b=b*10+s[i]-'0';
	}
	a+=b;
	b=x+y;
	while (a||b){
		while (a&&a%10==0)a/=10;
//		while (b&&b%10==0)b/=10;
		if (a%10!=b%10){puts("NO");return 0;}
		a/=10;b/=10;
	}
	puts("YES");
	return 0;
}