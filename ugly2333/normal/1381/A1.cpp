//CF1381A
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
char a[N],b[N];
int n;
vector<int> v;
int main()
{
	int T,i,l,r,f;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,a+1,b+1);
		l=1,r=n,f=0;
		v.clear();
		for(i=n;i>=1;i=i-1){
			if((a[r]^f)!=b[i]){
				if((a[l]^f)==b[i]){
					v.push_back(1);
					a[l]^=1;
				}
				v.push_back(i);
				swap(l,r);
				f^=1;
			}
			if(l<r)
				r--;
			else
				r++;
		}
		n=v.size();
		printf("%d",n);
		for(i=0;i<n;i=i+1)
			printf(" %d",v[i]);
		printf("\n");
	}
	return 0;
}