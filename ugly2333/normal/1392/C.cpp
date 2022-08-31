//CF1392C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,a[N];
int main()
{
	int T,i;
	LL x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i=i+1)
			scanf("%d",a+i);
		x=0;
		for(i=1;i<n;i=i+1)
			if(a[i]>a[i+1])
				x+=a[i]-a[i+1];
		cout<<x<<endl;
	}
	return 0;
}