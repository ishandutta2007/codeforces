//CF1707B
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
const int N = 111111;
int n,a[N];
int main()
{
	int T,i,r;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		reverse(a+1,a+n+1);
		for(r=n;r&&!a[r];r--);
		while(n>1){
			//for(i=1;i<=n;i++)cout<<a[i];cout<<' '<<r<<endl;
			for(i=1;i<r;i++)
				a[i]-=a[i+1];
			a[n]=0;
			n--;
			sort(a+1,a+r+1);
			reverse(a+1,a+r+1);
			while(r&&!a[r]){
				r--;
			}
		}
		printf("%d\n",a[1]);
	}
	return 0;
}