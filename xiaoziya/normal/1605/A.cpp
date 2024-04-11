#include<stdio.h>
#include<iostream>
using namespace std;
int T,a,b,c;
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",((a+b+c)%3!=0));
	}
	return 0;
}