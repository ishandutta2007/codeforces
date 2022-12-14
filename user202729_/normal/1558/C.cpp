// hopefully fast enough
// this one is definitely easier than AB
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int n; std::cin>>n;
	std::vector<int> a(n);
	std::vector<int> pos(n);
	bool fail=false;
	for(int posx=0; posx<n; ++posx){
		int x; std::cin>>x; --x;
		a[posx]=x; pos[x]=posx;
		if(posx%2u!=x%2u) fail=true;
	}

	if(fail){
		std::cout<<"-1\n";
		return;
	}

	auto const operate=[&](int len)->void{
		assert(len%2!=0);
		std::cout<<len<<' ';
		for(int i=0; i<len-1-i; i++){
			std::swap(a[i], a[len-1-i]);
			pos[a[i]]=i;
			pos[a[len-1-i]]=len-1-i;
		}
	};

	std::cout<<(n-1)/2*5<<'\n';
	for(int b=n-1; b!=0; b-=2){
		int const a=b-1;
		operate(pos[b]+1);
		assert(pos[b]==0);

		operate(pos[a]);
		assert(pos[b]==pos[a]-1);

		operate(pos[a]+2);
		assert(pos[b]==pos[a]+1);

		operate(pos[b]+1);
		assert(pos[b]==0);
		assert(pos[a]==1);

		operate(b+1);
		assert(pos[b]==b);
		assert(pos[a]==a);
	}
	std::cout<<'\n';

	for(int i=0; i<n; ++i)
		assert(pos[i]==i);





	

}