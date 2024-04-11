//CF1456B
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
int n,a[N],b[N];
int main()
{
	int i,j,k,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		b[i]=b[i-1]^a[i];
	}
	for(i=2;i<n;i=i+1){
		if((a[i-1]^a[i])>a[i+1]){
			cout<<1;
			return 0;
		}
		if(a[i-1]>(a[i]^a[i+1])){
			cout<<1;
			return 0;
		}
	}
	ans=N;
	for(i=0;i<=n;i=i+1)
		for(j=i+1;j<=n;j=j+1)
			for(k=j+1;k<=n;k=k+1)
				if((b[i]^b[j])>(b[j]^b[k]))
					ans=min(ans,k-i-2);
	if(ans==N)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}