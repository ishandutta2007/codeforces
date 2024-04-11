//CF1070J
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
const int M = 26;
const LL inf = 1e18;
int n,m,k,a[M],f[N];
LL ans;
char s[N];
int main()
{
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d%d%s",&n,&m,&k,s);
		for(i=0;i<k;i=i+1)
			a[s[i]-'A']++;
		f[0]=1;
		for(i=0;i<M;i=i+1)
			if(a[i])
				for(j=k;j>=a[i];j=j-1)
					f[j]+=f[j-a[i]];
		ans=inf;
		for(i=0;i<M;i=i+1){
			if(!a[i])
				continue;
			for(j=a[i];j<=k;j=j+1)
				f[j]-=f[j-a[i]];
			for(j=0;j<=k;j=j+1)
				if(f[j]&&j+a[i]>=n&&k-j>=m)
					ans=min(ans,max((LL)0,(LL)(n-j)*(m-(k-j-a[i]))));
			for(j=k;j>=a[i];j=j-1)
				f[j]+=f[j-a[i]];
		}
		cout<<ans<<endl;
		for(i=0;i<M;i=i+1)
			a[i]=0;
		for(i=0;i<=k;i=i+1)
			f[i]=0;
	}
	return 0;
}