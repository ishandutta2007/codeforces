#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
const int p=1e9+7;
int main()
{
	int n;
	scanf("%d",&n);
	int v1=1,v2=1;
	for(int i=1;i<=n;i++) v1=1ll*v1*i%p;
	for(int i=1;i<n;i++) v2=v2*2%p;
	printf("%d",((v1-v2)%p+p)%p);	
	return 0;
}