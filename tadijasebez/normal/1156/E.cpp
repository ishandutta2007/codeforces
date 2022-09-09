#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int L=18;
int p[N],rmq[N][L],pos[N];
ll Solve(int l,int r){
	if(l>r)return 0;
	int k=__builtin_clz(1)-__builtin_clz(r-l+1);
	int mx=max(rmq[l][k],rmq[r-(1<<k)+1][k]);
	int mid=pos[mx],ans=0;
	if(mid-l<r-mid){
		for(int i=l;i<mid;i++){
			int t=mx-p[i];
			if(pos[t]>mid && pos[t]<=r)
				ans++;
		}
	}else{
		for(int i=mid+1;i<=r;i++){
			int t=mx-p[i];
			if(pos[t]>=l && pos[t]<mid)
				ans++;
		}
	}
	return ans+Solve(l,mid-1)+Solve(mid+1,r);
}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++){
		scanf("%i",&p[i]);
		pos[p[i]]=i;
		rmq[i][0]=p[i];
	}
	for(int j=1;j<L;j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
			rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
	printf("%lld\n",Solve(1,n));
	return 0;
}