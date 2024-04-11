#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se secnod
#define mp make_pair
#define pii pair<int,int>
const int N=1000005,M=998244353;
int n,x[N],y[N],T;
inline int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&x[i]);
		for (int i=1;i<=n;i++)scanf("%d",&y[i]);
		sort(x+1,x+n+1);sort(y+1,y+n+1);
		for (int i=1;i<=n;i++)printf("%d ",x[i]);
		puts("");
		for (int i=1;i<=n;i++)printf("%d ",y[i]);
		puts("");
	}
}