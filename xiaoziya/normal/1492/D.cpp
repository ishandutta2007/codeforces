#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=400005;
int a,b,k,len;
int rec[maxn];
int main(){
	scanf("%d%d%d",&a,&b,&k);
	if(k==0){
		puts("Yes");
		for(int i=1;i<=b;i++)
			putchar('1');
		for(int i=1;i<=a;i++)
			putchar('0');
		putchar('\n');
		for(int i=1;i<=b;i++)
			putchar('1');
		for(int i=1;i<=a;i++)
			putchar('0');
		putchar('\n');
		return 0;
	}
	if(a+b-2-k<0||a==0||b==1){
		puts("No");
		return 0;
	}
	puts("Yes");
	a--,b-=2,len=a+b;
	putchar('1'),putchar('1');
	for(int i=1;i<k;i++){
		if(a)
			rec[i]=0,a--;
		else rec[i]=1,b--;
		putchar(rec[i]+48);
	}
	putchar('0');
	for(int i=k;i<=len;i++){
		if(a)
			rec[i]=0,a--;
		else rec[i]=1,b--;
		putchar(rec[i]+48);
	}
	putchar('\n');
	putchar('1'),putchar('0');
	for(int i=1;i<k;i++)
		putchar(rec[i]+48);
	putchar('1');
	for(int i=k;i<=len;i++)
		putchar(rec[i]+48);
	putchar('\n');
	return 0;
}