//CF 569B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int a[111111],s[111111];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		s[a[i]]++;
	}
	j=1;
	for(i=1;i<=n;i=i+1){
		if(a[i]<=n&&s[a[i]]==1)
			continue;
		while(s[j]){
			j++;
		}
		s[a[i]]--;
		a[i]=j;
		s[j]++;
	}
	for(i=1;i<=n;i=i+1)
		printf("%d ",a[i]);
	return 0;
}