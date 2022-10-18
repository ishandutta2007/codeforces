#include<bits/stdc++.h>
#define lf double
#define ll long long
#define eps 1e-10
#define mp std::make_pair
#define fir first
#define sec second
#define N 100005

const lf pi=std::acos(-1);

int n;
ll k;
lf a[N],b[N],d[N];

int t[N<<1];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,int y){
	for(;x<=2*n;x+=lb(x))
		t[x]+=y;
}
inline int sum(int x){
	int res=0;
	for(;x;x-=lb(x))
		res+=t[x];
	return res;
}

inline bool chk(lf R){
	ll res=1ll*n*(n-1)/2;
	std::vector<lf> val;
	std::vector<std::pair<lf,lf>> q;
	for(int i=1;i<=n;i++)
		if(d[i]>R+eps){
			lf x=std::atan2(b[i],a[i]),y=std::acos(R/d[i]);
			lf l=x-y,r=x+y;
			if(l<0)
				l+=2*pi;
			if(r<0)
				r+=2*pi;
			if(l>r)
				std::swap(l,r);
			val.push_back(l);
			val.push_back(r);
			q.push_back(mp(r,l));
		}
	std::sort(val.begin(),val.end());
	val.erase(std::unique(val.begin(),val.end()),val.end());
	std::sort(q.begin(),q.end());
	memset(t,0,sizeof(t));
	for(auto [x,y]:q){
		int u=std::lower_bound(val.begin(),val.end(),x)-val.begin()+1;
		int v=std::lower_bound(val.begin(),val.end(),y)-val.begin()+1;
		res-=sum(u)-sum(v-1);
		add(v,-1),add(u,1);
		
	}
	return res<k;
}

int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&a[i],&b[i]);
		d[i]=std::sqrt(a[i]*a[i]+b[i]*b[i]);
	}
	lf l=0,r=1e9;
	for(int _=0;_<50;_++){
		lf mid=(l+r)/2;
		if(chk(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%.11lf\n",l);
}