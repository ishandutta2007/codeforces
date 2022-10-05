#include <bits/stdc++.h>
using namespace std;
int x,y,z;
int main(){
	cin>>x>>y>>z;
	int a=x-y+z,b=x-y-z;
	if(a==b&&a==0)	puts("0");
	else if(a<0)	puts("-");
	else if(b>0)	puts("+");
	else 			puts("?");
	return 0;
}