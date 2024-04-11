// iirc?...
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct DSU{
	struct Item{unsigned parent: 31, full: 1;};
	std::vector<Item> p;
	DSU():p(){}
	DSU(int n):p(){reset(n);}
	void reset(unsigned n){
		p.resize(n);
		while(n--)p[n]={n, 0};
	}
	int root(int x){
		return p[x].parent!=x?p[x].parent=root(p[x].parent):x;
	}
};
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n, m; std::cin>>n>>m;
	struct T{int a, b, w;};
	std::vector<T> t(m);
	for(auto &[a, b, w]: t){
		std::cin>>a>>b>>w;
		--a;--b;
	}
	std::sort(begin(t), end(t),[&](T first, T sec){return first.w>sec.w;});

	DSU data(n);
	int64_t result{};
	for(auto  [a, b, w]: t){
		a=data.root(a);
		b=data.root(b);
		if(a==b){
			if(data.p[a].full){
			}else{
				data.p[a].full=1;
				result+=w;
			}
		}else{
			if(data.p[a].full and data.p[b].full){
			}else{
				data.p[a].full|=data.p[b].full;
				data.p[b].parent=a;
				result+=w;
			}
		}
	}
	std::cout<<result<<'\n';
}