#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int T,a,b;
int gcd(int a,int b){
	int r=a%b;
	while(r!=0){a=b,b=r,r=a%b;}
	return b;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if(gcd(a,b)==1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}