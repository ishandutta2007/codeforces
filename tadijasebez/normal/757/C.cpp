#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=1000500;
const int mod=1e9+7;
vector<int> v[N];
int sum=1,n,m,i,F[N],ans=1,k,x,j;
int main()
{
	scanf("%i %i",&n,&m);
	F[1]=1;
	for(i=2;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	while(n){
		scanf("%i",&k);
		while(k--){
			scanf("%i",&x);
			v[x].push_back(n);
		}
		n--;
	}
	sort(v+1,v+1+m);
	for(i=2;i<=m;i++)
	{
		if(v[i]==v[i-1]) sum++;
		else ans=(ll)ans*F[sum]%mod,sum=1;
	}
	ans=(ll)ans*F[sum]%mod;
	printf("%i\n",ans);
	return 0;
}