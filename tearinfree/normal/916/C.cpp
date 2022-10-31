#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <vector>

using namespace std;
typedef long long lli;
typedef pair<lli,int> pli;

int n,m;
int vis[120001];
vector<int> prime;
int main() {
	scanf("%d%d",&n,&m);
	for(int i=2;i<=120000;i++) {
		if(!vis[i]) {
			prime.push_back(i);
			for(lli j=1ll*i*i;j<=120000;j+=i) vis[j]=1;
		}
	}

	int val=*lower_bound(prime.begin(),prime.end(),n);
	printf("%d %d\n",val,val);
	
	int t=val-(n-2);
	for(int i=1;i<n-1;i++) printf("%d %d %d\n",i,i+1,1);
	printf("%d %d %d\n",n-1,n,t);
	
	t=val+20;
	m-=n-1;
	for(int i=1;i<n && m;i++) {
		for(int j=i+2;j<=n && m;j++) {
			m--;
			printf("%d %d %d\n",i,j,t);
		}
	}
	
	return 0;
}