#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
#define N 300000
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

int n,k,a[N],cnt[N],b[N],m=0;

int main(){
	CL(cnt);CL(b);
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d",&a[i]);
		++cnt[a[i]];
	}
	int l=1,r=n,tot,maxx=0;
	while(l<=r){
		int mid=(l+r)/2;
		tot=0;
		rep(i,1,200000){
			tot+=(cnt[i]/mid);
		}
		if(tot>=k){
			maxx=mid;l=mid+1;
		}else r=mid-1;
	}
	rep(i,1,200000){
		rep(j,1,(cnt[i]/maxx)){
			b[++m]=i;
		}
	}
	rep(i,1,k)cout<<b[i]<<" ";
	return 0;
}