#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>a[1020];
int n,k,x,z;
int A(vector<int>&v,int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin();
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		a[i].resize(k);
		for(int j=0;j<k;j++)
			scanf("%d",&a[i][j]);
		sort(a[i].begin(),a[i].end());
	}
	for(int i=0;i<n;i++)
		for(int L=(i+n-1)%n,R=(i+1)%n,j=1;j<a[i].size();j++)
			if(A(a[L],a[i][j])-A(a[L],a[i][j-1])!=A(a[R],a[i][j])-A(a[R],a[i][j-1]))
				z++;
	printf("%d",z);
	return 0;
}