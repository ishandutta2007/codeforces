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

#define N 100100

long long s1,s2,s3,res=0;
int k[N],n,a[N];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&n);
	s1=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s1+=a[i];
	}
	if (s1%3){
		puts("0");
		return 0;
	}
	s3=s1/3;s2=0;k[0]=0;
	for (int i=1;i<=n;i++){
		s2+=a[i];
		k[i]=k[i-1]+(s2==s3);
	}
	s2=0;
	for (int i=n;i>1;i--){
		s2+=a[i];
		if (s2==s3)res+=k[i-2];
	}
	printf("%I64d\n",res);
	return 0;
}