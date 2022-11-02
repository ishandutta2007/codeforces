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
#define ll long long 
ll a,b;

int main(){
	scanf("%lld%lld",&a,&b);
	if(b==0||a==0){
		printf("%lld %llld\n",a,b);
		return 0;
	}
	while(a&&b){
		if(a>=2*b){
			ll t=a/(2*b);
			a-=t*2*b;
			if(!a) break;
			continue;
		}
		if(b>=2*a){
			ll t=b/(2*a);
			b-=t*2*a;
			if(!b) break;
		}
		else break;
	}
	printf("%lld %lld\n",a,b);
	return 0;
}