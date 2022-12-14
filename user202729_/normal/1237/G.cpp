#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>
#include<unordered_map>

std::vector<int> a;
int maxd;
int n,k;

auto print_op(int x){
	std::cout<<x%n;
	for(int i=0;i<k;++i)
		std::cout<<' '<<a[(x+i)%n]-a[(x+i+n-1)%n]+maxd;
	std::cout<<'\n';
}

void process(int l,int r){
	assert(std::cerr<<"process "<<l<<' '<<r<<'\n');
	assert(a[l%n]==0&&a[r%n]==0&&l<r);
	if(l+1==r)
		return;

	int x=r;
	do{
		x-=k-1;
	}while(x>l&&a[x%n]>0);

	if(x>l){
		for(int i=0;i<k-1;++i)
			a[(x+i)%n]=0;

		print_op(x);

		process(x+k-2,r); // all high. contains some redundant check
		process(l,x);
		return;
	}

	x+=k-1;
	if(l+1<x){
		for(int i=l+1;i<x;++i)
			a[i%n]=0;
		print_op(l+1);
	}

	for(;x!=r;x+=k-1){
		for(int i=0;i<k-1;++i)
			a[(x+i)%n]=0;
		print_op(x);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n>>k;
	a.resize(n);
	for(int& x:a)std::cin>>x;

	//auto olda=a;

	for(int i=1;i<n;++i)
		a[i]+=a[i-1];

	maxd=a.back()/n;
	for(int i=0;i<n;++i)
		a[i]-=(i+1)*maxd;

	std::vector<int> f(n),g(n);
	// f[i] = min fi s.t. i+1 == fi mod k-1, a[i] == a[fi%n]
	// g[i] = min gi > i s.t. a[gi] != a[i]

	std::vector<std::unordered_map<int,int>> colmod(k-1);
	// colmod[mod][col] = min index i > current index, == mod (mod k-1), a[i]==col
	for(int i=2*n,
			lastsplit=2*n; // a[lastsplit] != a[lastsplit-1]
			i--;){

		colmod[i%(k-1)][a[i%n]]=i;

		auto iter=colmod[i%(k-1)].find(a[(i+n-1)%n]);
		if(i<n)
			f[i]=iter==end(colmod[i%(k-1)]) ? 2*n : iter->second;

		if(a[i%n]!=a[(i+1)%n])
			lastsplit=i+1;

		if(i<n)
			g[i]=lastsplit;
	}

	struct jumpentry{
		int dlen,nblock;
	};
	std::vector<std::vector<jumpentry>> jt;
	jt.resize(1);

	//g.resize(n+1);g[n]=n; // placeholder

	{
		auto& jump=jt[0];
		//jump.resize(n+1);jump[n]={n+1,n+1}; // placeholder
		jump.resize(n);
		for(int i=0;i<n;++i){
			int fi=f[i];
			if(fi<2*n){
				assert((fi-i)%(k-1)==0);
				jump[i].nblock=(fi-i)/(k-1);
				jump[i].dlen= ( fi>=n ? g[fi-n]+n : g[fi] ) - i;
			}else{
				jump[i]={2*n+1,2*n+1};
			}
		}
	}

	while(true){
		auto const& a=jt.back();
		auto b=a;
		bool useful=false;
		for(int i=0;i<n;++i){
			jumpentry& e=b[i];
			jumpentry nexte=a[(e.dlen+i)%n];

			e.dlen+=nexte.dlen;
			e.nblock+=nexte.nblock;
			if(e.dlen<=n)
				useful=true;
			else
				e.dlen=n+1;
		}
		if(useful)
			jt.push_back(std::move(b));
		else
			break;
	}

	auto const ceildiv=[](int a,int b){return (a+b-1)/b;};
	int ans=ceildiv(n-1,k-1);
	int besti=-1;

	for(int i=0;i<n;++i){
		int nblock=0;
		int dlen=0;
		int x=i;
		for(auto j=jt.size();j--;){
			auto e=jt[j][x];
			if(e.dlen+dlen<n){
				dlen+=e.dlen;
				x=(x+e.dlen)%n;
				nblock+=e.nblock;
			}
		}
		assert(dlen<n);
		dlen+=jt[0][x].dlen;
		nblock+=jt[0][x].nblock;
		assert(dlen>=n);
		if(nblock<ans){
			ans=nblock;
			besti=i;
		}
	}

	std::cout<<ans<<'\n';

	
	if(besti<0){
		std::transform(begin(a),end(a),begin(a),[x=a[0]](int y){return y-x;});
		process(0,n);
	}else{
		auto const& jump=jt[0];
		std::transform(begin(a),end(a),begin(a),[x=a[(besti+n-1)%n]](int y){return y-x;});

		int nblock=0;
		int dlen=0;
		int x=besti;

		while(nblock<ans){
			auto e=jump[x];
			if(nblock+e.nblock<=ans){
				process(x+n-1, x+n+e.nblock*(k-1));
				dlen+=e.dlen;
				x=(x+e.dlen)%n;
				nblock+=e.nblock;
			}
		}
		assert(ans==nblock);
		assert(ans==0||dlen>=n);
	}
}