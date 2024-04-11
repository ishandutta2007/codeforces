#include<bits/stdc++.h>
#define ull unsigned long long

int n,m;

inline int bc(ull x){
	return __builtin_popcount(x>>32)+__builtin_popcount(x);
}

std::vector<std::pair<ull,ull>> f,g;

int a[45];

ull b[45];

int main(){
	scanf("%d%d",&n,&m);
	f.push_back({0,0});
	while(m--){
		g.clear();
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d",&a[i]);
			a[i]--;
			b[i]=b[i-1]|(1ull<<a[i]);
		}
		for(auto [x,y]:f){
			int c0=bc(x&b[k]),c1=bc(y&b[k]);
			for(int i=0;i<=k-c0-c1;i++)
				g.push_back({(x&(~b[k]))|b[c0+i],(y&(~b[k]))|(b[k]^b[c0+i])});
		}
		std::swap(f,g);
	}
	bool flg=1;
	for(auto [x,y]:f){
		bool t=0;
		for(int i=0;i<n;i++){
			int tmp=(x>>i)&1?0:(y>>i)&1?1:2;
			if(!(tmp&1)&&t){
				flg=0;
				break;
			}
			if(tmp)
				t=1;
		}
	}
	puts(flg?"ACCEPTED":"REJECTED");
}