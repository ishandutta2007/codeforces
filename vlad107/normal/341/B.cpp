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

#define mp make_pair
#define pb push_back
#define INF 1000000000

#define N 500500

using namespace std;

int a[N],f[N],n,ans;

int fmax(int x){
	int res=0;
	while (x>0){
		res=max(res,f[x]);
		x=(x&(x-1));
	}
	return res;
}

void modify(int x,int val){
	while (x<=n){
		f[x]=max(f[x],val);
		x=(x|(x-1))+1;
	}
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<n;i++){
		int x=fmax(a[i])+1;
		if (x>ans)ans=x;
		modify(a[i],x);
	}
	printf("%d\n",ans);
}