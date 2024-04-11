#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define N 6666
#define M 19000000

using namespace std;

int n,a[N],S,u;
bool prime[M],found;

int main(){
	scanf("%d",&n);
	memset(prime,true,sizeof(prime));
	prime[0]=0;prime[1]=0;
	S=n*(n+1)/2;
	for (int i=2;i<=S;i++)
		if (prime[i])
			for (int j=i+i;j<=S;j+=i)prime[j]=false;
	if (prime[S]){
		for (int i=1;i<=n;i++)printf("1 ");
		puts("");
		return 0;
	}
	for (int i=1;i<=n;i++)a[i]=1;
	found=false;
	for (int x=1;x<S;x++)
		if ((prime[x])&&(prime[S-x])){
			u=x;
			found=true;
			break;
		}
	if (found){
		for (int i=n;i>=1;i--)
			if (u>=i){
				a[i]=2;
				u-=i;
			}else a[i]=1;
		int x=0,y=0;
		for (int i=1;i<=n;i++)
			if (a[i]==1)x+=i;else y+=i;
		if ((!prime[x])||(!prime[y])){
			puts("mistake");
		}
		for (int i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
		return 0;
	}
	if (n>=3){
		a[3]=3;
		for (int i=1;i<S-3;i++)
			if ((prime[i])&&(prime[S-i-3])){
				u=i;
				found=1;
				break;
			}
		for (int i=n;i>=1;i--)
			if ((i!=3)&&(u>=i)){
				a[i]=2;
				u-=i;
			}else 
			if (i!=3)a[i]=1;
		int x=0,y=0,z=0;
		for (int i=1;i<=n;i++)
			if (a[i]==1)x+=i;else
			if (a[i]==2)y+=i;else
			z+=i;
		if ((!prime[x])||(!prime[y])||(!prime[z])){
			puts("mistake");
			return 0;
		}
		for (int i=1;i<=n;i++)printf("%d ",a[i]);
	}else puts("-1");
}