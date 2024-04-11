//CF1610B
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
int chk(int x){
	int l=1,r=n;
	while(l<r){
		if(a[l]==x)
			l++;
		else{
			if(a[r]==x)
				r--;
			else{
				if(a[l]!=a[r])
					return 0;
				l++;
				r--;
			}
		}
	}
	return 1;
}
int main()
{
	int T,i,l,r;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		l=1,r=n;
		while(l<=r){
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else
				break;
		}
		if(l<r){
			if(chk(a[l])||chk(a[r]))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			printf("YES\n");
	}
	return 0;
}