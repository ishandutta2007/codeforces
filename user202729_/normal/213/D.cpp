// Fortunately, a submission that fails on sample test case is
// not counted to (preposition usage correct?) the penalty.

// UPD: I should have read the problem statement more carefully... took me 10 minutes.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<complex>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	using cd=std::complex<double>;
	cd const pentedge=cd{10,0}*std::pow(cd(-1),0.12345678); // could the problem be negative zero? I don't think so
	// but just try it. It's too hard to look at the output...
	cd const rot72=std::pow(cd(-1),2./5);

	cd const segment=pentedge+pentedge*rot72;
	cd const offset1=pentedge*rot72;
	cd const offset2=-offset1*rot72;
	cd const offset3=offset2+offset2*rot72;

	auto const eq=[](double a,double b){
		return std::abs(a-b)<1e-14;
	};
	assert(eq(std::abs(offset1),10));
	assert(eq(std::abs(offset2),10));
	assert(eq(std::abs(offset3-offset2),10));
	assert(eq(std::abs(segment-offset1),10));
	assert(eq(std::abs(segment-offset3),10));

	std::cout<<std::fixed<<std::setprecision(12);
	auto const pr=[](cd x){
		std::cout<<real(x)<<' '<<imag(x)<<'\n';
	};

	{
		std::cout<<4*n+1<<'\n';
		cd base=0;
		for(int i=0;;++i){
			pr(base);
			if(i==n)break;
			pr(base+offset1);
			pr(base+offset2);
			pr(base+offset3);
			base+=segment;
		}
	}

	for(int i=0;i<n;++i){
		std::cout
			<<i*4+1<<' '
			<<i*4+2<<' '
			<<i*4+5<<' '
			<<i*4+4<<' '
			<<i*4+3<<'\n';
	}

	std::cout<<'1';
	for(int i=0;i<n;++i) std::cout<<' '<<i*4+5;
	for(int i=n;i--;){
		std::cout
			<<' '<<i*4+3
			<<' '<<i*4+2
			<<' '<<i*4+4
			<<' '<<i*4+1;
	}
	std::cout<<'\n';
}