//CF1168B
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
const int N = 333333;
int n,a[N];
char s[N];
int main()
{
	int i,j,k,o;
	LL ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i=i+1)
		a[i]=s[i]-'0';
	ans=(LL)n*(n-1)/2;
	for(i=1;i<=n;i=i+1){
		o=1;
		for(j=i+1;o&&j<=n;j=j+1){
			for(k=j-1;k+k-j>=i;k=k-1)
				if(a[k]==a[j]&&a[k+k-j]==a[j])
					o=0;
			ans-=o;
		}
	}
	cout<<ans;
	return 0;
}