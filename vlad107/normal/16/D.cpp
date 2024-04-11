#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>
#include <functional>

int n,res=1,x,px,k=1;
char s[1000];

int geta(){
	gets(s);
	s[1]-='0';s[2]-='0';
	s[4]-='0';s[5]-='0';
	x=s[1]*10+s[2];
	x%=12;
	x=x*60+s[4]*10+s[5];
	if (s[7]=='p')x+=720;
	x%=1440;
	return x;
}           

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d\n",&n);
	px=geta();
	for (int i=1;i<n;i++){
		x=geta();
		if (x<px)res++;
		if (x==px)k++;
		if (k>10){
			k=1;
			res++;
		}
		if (x!=px)k=1;
		px=x;
	}
	printf("%d\n",res);
	return 0;
}