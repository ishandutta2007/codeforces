//CF1007A
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
	int i,l,r,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	l=1,r=n;
	for(i=1;i<=n;i=i+1){
		if(a[l]<a[i])
			s++,l++;
		else
			r--;
	}
	cout<<s;
	return 0;
}