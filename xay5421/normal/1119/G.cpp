#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=1000005;
int n,m,a[N];
int main(){
	scanf("%d%d",&n,&m);
	vector<int>v{0,n};
	LL sum=0;
	rep(i,1,m)scanf("%d",&a[i]),sum+=a[i],i<m&&(v.PB(sum%n),0);
	sort(v.begin(),v.end());
	vector<int>sz;
	rep(i,1,SZ(v)-1){
		sz.PB(v[i]-v[i-1]);
	}
	printf("%lld\n",(sum+n-1)/n);
	rep(i,0,SZ(sz)-1)printf("%d ",sz[i]);
	puts("");
	int j=0;
	rep(i,1,m){
		while(a[i]>0){
			printf("%d ",i);
			a[i]-=sz[j];
			++j%=SZ(sz);
			if(!j)puts("");
		}
	}
	while(j){
		printf("%d ",m);
		++j%=SZ(sz);
	}
	return 0;
}