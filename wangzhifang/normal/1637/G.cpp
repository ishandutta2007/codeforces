#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;
vector<pair<int,int> >opt;
void solve1(const int n,const int d,const int r){
	if(!n)
		return;
	if(n*2<=r){
		const int half=r/2;
		solve1(n,d,half);
		for(int i=n/2; i; --i)
			opt.emplace_back(half*d,half*d);
		if((n&1)){
			opt.emplace_back(0,half*d);
			opt.emplace_back(half*d,half*d);
		}
		for(int i=n/2; i; --i)
			opt.emplace_back(0,r*d);
		return;
	}
	if(n==r){
		solve1(n-1,d,r);
		return;
	}
	if(n==r-1){
		const int half=r/2;
		for(int i=1; i<half; ++i)
			opt.emplace_back(i*d,(r-i)*d);
		opt.emplace_back(r/2*d,r/2*d);
		for(int i=2; i<half; i+=2)
			opt.emplace_back(i*d,(r-i)*d);
		if(r>4)
			solve1(r/4-1,4*d,r/4);
		opt.emplace_back(0,r*d);
		return;
	}
	const int p=r-n,half=r/2;
	solve1(p-1,d,r);
	opt.emplace_back(0,half*d);
	opt.emplace_back(half*d,half*d);
	for(int i=p; i<half; ++i)
		opt.emplace_back(i*d,(r-i)*d);
	solve1(half-p,2*d,r/2);
}
void solve(const int n,const int d,const int r){
	if(n*2<=r){
		const int half=r/2;
		solve(n,d,half);
		for(int i=(n-1)/2; i; --i)
			opt.emplace_back(half*d,half*d);
		if(!(n&1)){
			opt.emplace_back(0,half*d);
			opt.emplace_back(half*d,half*d);
		}
		for(int i=(n-1)/2; i; --i)
			opt.emplace_back(0,r*d);
		return;
	}
	if(n==r){
		solve(n-1,d,r);
		return;
	}
	if(n==r-1){
		const int half=r/2;
		for(int i=1; i<half; ++i)
			opt.emplace_back(i*d,(r-i)*d);
		opt.emplace_back(r/2*d,r/2*d);
		for(int i=2; i<half; i+=2)
			opt.emplace_back(i*d,(r-i)*d);
		if(r>4)
			solve1(r/4-1,4*d,r/4);
		return;
	}
	const int p=r-n,half=r/2;
	if(p-1>2){
		solve(p-1,d,r);
		opt.emplace_back(0,half*d);
		opt.emplace_back(half*d,half*d);
		for(int i=p; i<half; ++i)
			opt.emplace_back(i*d,(r-i)*d);
		solve1(half-p,2*d,r/2);
		return;
	}
	if(half-p>2){
		for(int i=p; i<half; ++i)
			opt.emplace_back(i*d,(r-i)*d);
		solve(half-p,2*d,r/2);
		opt.emplace_back(0,half*d);
		opt.emplace_back(half*d,half*d);
		solve1(p-1,d,r);
		return;
	}
	if(n==5){
		opt.emplace_back(3*d,5*d);
		opt.emplace_back(2*d,2*d);
		opt.emplace_back(4*d,4*d);
		opt.emplace_back(0,8*d);
		solve1(1,d,r);
		return;
	}
	if(n==6){
		opt.emplace_back(3*d,5*d);
		opt.emplace_back(2*d,6*d);
		opt.emplace_back(4*d,4*d);
		solve1(2,d,r);
		return;
	}
}
void test(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("1 0");
		return;
	}
	if(n==2){
		puts("-1");
		return;
	}
	const int r=1<<(32-__builtin_clz(n-1));
	opt.clear();
	solve(n,1,r);
	opt.emplace_back(0,r);
	printf("%zd\n",opt.size());
	for(const pair<int,int>&x:opt)
		printf("%d %d\n",x.first,x.second);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}