#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 100005

int T;

int n,a[N];

std::vector<int> p,q;

int t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,int d){
	for(;x<=n;x+=lb(x))
		t[x]+=d;
}
inline int sum(int x){
	int res=0;
	for(;x;x-=lb(x))
		res+=t[x];
	return res;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int c0=0,c1=0;
		p.clear(),q.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]&=1;
			if(a[i]){
				q.push_back(i);
				c1++;
			}
			else{
				p.push_back(i);
				c0++;
			}
		}
		std::reverse(p.begin(),p.end());
		std::reverse(q.begin(),q.end());
		if(c0>c1+1||c1>c0+1){
			puts("-1");
			continue;
		}
		ll ans=inf;
		if(c0>=c1){
			auto pp=p,qq=q;
			ll tmp=0;
			for(int i=1;i<=n;i++)
				add(i,1);
			for(int i=1;i<=n;i++){
				if(i&1){
					int x=pp.back();
					pp.pop_back();
					tmp+=sum(x)-1;
					add(x,-1);
				}
				else{
					int x=qq.back();
					qq.pop_back();
					tmp+=sum(x)-1;
					add(x,-1);
				}
			}
			ans=std::min(ans,tmp);
		}
		if(c1>=c0){
			ll tmp=0;
			for(int i=1;i<=n;i++)
				add(i,1);
			for(int i=1;i<=n;i++){
				if(i&1){
					int x=q.back();
					q.pop_back();
					tmp+=sum(x)-1;
					add(x,-1);
				}
				else{
					int x=p.back();
					p.pop_back();
					tmp+=sum(x)-1;
					add(x,-1);
				}
			}
			ans=std::min(ans,tmp);
		}
		printf("%lld\n",ans);
	}
}