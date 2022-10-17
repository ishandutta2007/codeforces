#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if (n>36) puts("-1"); else{
		while (n){
			if (n>=2) putchar('8'),n-=2; else
			putchar('4'),n--;
		}
	}
	return 0;
}