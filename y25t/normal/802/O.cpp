#include<bits/stdc++.h>
#define ll long long
#define N 500005

int n,m,a[N],b[N];

inline std::pair<int,ll> chk(int x){
	int cnt=0;
	ll res=0;
	std::priority_queue<std::pair<int,int>> q;
	for(int i=n;i;i--){
		q.emplace(-b[i],1),q.emplace(a[i]-x,0);
		auto [u,v]=q.top();
		q.pop();
		res+=a[i]-x-u,cnt+=v;
	}
	return {cnt,res};
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	int L=0,R=2e9,res=0;
	while(L<=R){
		int mid=((ll)L+R)>>1;
		if(chk(mid).first<=m)
			res=mid,L=mid+1;
		else
			R=mid-1;
	}
	printf("%lld\n",chk(res).second+1ll*m*res);
}