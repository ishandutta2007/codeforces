/*
 * While this is (supposed to be) an easy problem, I could not solve it during the virtual contest.
 * I spent about an hour considering the maximum flow approach (failed), and some 30 minutes to
 * implement a local optimization approach (also failed).
 *
 * It's easy to observe that the answer is at most n. However it's hard to get the (seemingly obvious?)
 * result that if the answer is less than n, then there's an empty row/column.
 *
 * Idea: can the problem be solved if the cost of a square with side length n = n^a for a int ]1..2[ ?
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<array>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>

int fmem[51][51][51][51];
std::array<uint64_t,50> maskr,maskc;

int f(int u,int d,int l,int r){
	if(u==d or l==r)
		return 0;
	assert(u<d and l<r);
	int& curmem=fmem[u][d][l][r];
	if(curmem>=0) return curmem;

	int out;
	if(d-u>r-l){
		out=d-u;
		auto const mask=((uint64_t)-1<<l)^((uint64_t)-1<<r);
		for(int x=u;x<d;++x)
			if(0==(maskr[x]&mask))
				out=std::min(out,f(u,x,l,r)+f(x+1,d,l,r));
	}else{
		out=r-l;
		auto const mask=((uint64_t)-1<<u)^((uint64_t)-1<<d);
		for(int x=l;x<r;++x)
			if(0==(maskc[x]&mask))
				out=std::min(out,f(u,d,l,x)+f(u,d,x+1,r));
	}
	return curmem=out;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	std::memset((void*)fmem,-1,sizeof fmem);

	std::string row;row.reserve(n);
	for(int r=0;r<n;++r){
		std::cin>>row;
		for(int c=0;c<n;++c){
			if(row[c]=='#'){
				maskr[r]|=(uint64_t)1<<c;
				maskc[c]|=(uint64_t)1<<r;
			}
		}
	}

	std::cout<<f(0,n,0,n)<<'\n';
}