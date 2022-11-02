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
int n,a[109],sum;
int main(){
	scanf("%d",&n);sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=(a[i]>=0?a[i]:(-a[i]));
	} 
	printf("%d\n",sum);
	return 0;
}