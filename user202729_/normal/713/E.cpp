/* Despite people complaining that other problems are "classic" or "copy-pasted",
 * this one is pretty nice actually.
 *
 * There are some case-working, but I have to train on these kinstd:: of problems anyway
 *
 * [I didn't read the editorial or see any failed test cases]
 * [I had to write a test generator]
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>

template<bool right_may_overflow=true>
bool solve(std::vector<int> a /* locations mod m */,int m,int d /* max time */){
	// return (solvable if a[0] chooses left (counter clockwise)?)
	assert(a[0]==0);
	int tail=a[0]+m-d; // covered from right
	int head=a[0]; // covered from left

	if(right_may_overflow){
		if(solve<false>(a,m,d))return true;
		if(a.size()==1 or a.back()<=tail)
			return false;
		head=a.back()+d-m;
		a.pop_back();
	}

	std::vector<char>
		f(a.size()), // [i]: i points left, i-1 points right, no gap
		g(a.size()), // [i]: i points right, no gap
		h(a.size()); // [i]: i points left, i-1 points (unknown), covered ..a[i]
	int const n=(int)a.size();

	h[0]=true;
	for(int i=0;i<n;++i){
		if(f[i] or h[i]){
			int r=std::max(head,a[i]);
			if(f[i]) r=std::max(r,a[i-1]+d); // covered range

			if(r>=tail-1)
				return true;

			if(i<n-1 and a[i+1]-d<=r+1)
				h[i+1]=true;

			if(i<n-1 and a[i+1]<=r+1)
				g[i+1]=true;

			if(i<n-2 and a[i+2]-d<=r+1)
				f[i+2]=true;
		}

		if(g[i]){
			int r=std::max(head,a[i]+d);

			if(r>=tail-1)
				return true;

			if(i<n-1 and a[i+1]-d<=r+1)
				h[i+1]=true;

			if(i<n-1 and a[i+1]<=r+1)
				g[i+1]=true;

			if(i<n-1 and a[i+1]-d<=r+1)
				f[i+1]=true;

			if(i<n-2 and a[i+2]-d<=r+1)
				f[i+2]=true;
		}
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int m;std::cin>>m;
	int n;std::cin>>n;
	std::vector<int> a(n);
	for(int& x:a){
		std::cin>>x;
		--x;
	}
	assert(std::is_sorted(begin(a),end(a)));

	{
		int const x=a[0];
		std::transform(begin(a),end(a),begin(a),[x](int y){return y-x;});
	}

	int maxdiff=a[0]-a.back()+m;
	for(int i=1;i<n;++i)
		maxdiff=std::max(maxdiff,a[i]-a[i-1]);

	auto a0=a; // flipped direction
	std::reverse(++begin(a0),end(a0));
	std::for_each(++begin(a0),end(a0),[x=a[0], m](int& y){y=(x*2+m-y)%m;});
	assert(std::is_sorted(begin(a0),end(a0)));

	int d=maxdiff-1;
	int mind=maxdiff/2;
	assert(solve(a,m,d) and solve(a0,m,d)); // both direction of a must work
	assert(mind==0 or not(solve(a,m,mind-1) or solve(a0,m,mind-1)));

	for(int step=1<<30;step;step>>=1)if(d-step>=mind){
		if(solve(a,m,d-step) or solve(a0,m,d-step))
			d-=step;
	}
	std::cout<<d <<'\n';
}