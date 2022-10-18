#include<bits/stdc++.h>
#define N 200005

int n,a[N];

int f[N];

std::vector<int> V[N];

int t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,int d){
	for(;x<=n;x+=lb(x))
		t[x]=std::min(t[x],d);
}
inline int sum(int x){
	int res=n+1;
	for(;x;x-=lb(x))
		res=std::min(res,t[x]);
	return res;
}

inline void sol(){
	for(int i=1;i<=n;i++)
		V[i].clear();
	std::stack<int> st;
	for(int i=1;i<=n;i++){
		while(st.size()&&a[i]>a[st.top()])
			V[i].emplace_back(st.top()),st.pop();
		st.emplace(i);
	}
	for(int i=1;i<=n;i++)
		t[i]=n+1;
	std::set<std::pair<int,int>> s;
	for(int i=n;i;i--){
		while(s.size()){
			auto it=s.upper_bound({a[i],0});
			if(it==s.end())
				break;
			add(it->first,it->second),s.erase(it);
		}
		s.emplace(a[i],i);
		for(auto j:V[i])
			f[j]=std::min(f[j],sum(a[j]));
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		f[i]=n+1;
	sol();
	for(int i=1;i<=n;i++)
		a[i]=n-a[i]+1;
	sol();
	for(int i=n-1;i;i--)
		f[i]=std::min(f[i],f[i+1]);
	long long res=0;
	for(int i=1;i<=n;i++)
		res+=f[i]-i;
	printf("%lld\n",res);
}