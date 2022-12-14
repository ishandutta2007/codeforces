/*
[I've read the editorial]

{old comment

I knew (before read the editorial, of course) that the necessary condition is that the XOR
of all elements is 0, and predicted that it's also the sufficient condition (by writing
a brute force solution).

Splitting the set (a) into different cycles was a bad idea.
The idea of augmenting is not too hard to get (it's expected that the complexity is
near n^2), but when cycles of considered it's sometimes impossible to "augment" the path.

The nice part about this problem is the proof.
However, when somebody try to make a solution without cycle splitting, they may get AC without
proving it.
}

To fix the previous solution I didn't read the editorial, just write a test generator and
randomly change the code until it appear to be correct.
So (in theory) I could solve the problem int time if I believed that the solution is correct.
However a Codeforces contest only lasts 2 hours and there's little time to
test different approach.

*/

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int k;std::cin>>k;
	std::vector<int> target(1<<k);
	int xorall=0;
	for(int& ai:target){
		std::cin>>ai;
		xorall^=ai;
	}
	if(xorall!=0){
		std::cout<<"Fou\n";
		return 0;
	}

	std::vector<int> p(1<<k),q(1<<k),a(1<<k),ppos(1<<k);
	for(int i=1<<k;i--;)p[i]=q[i]=ppos[i]=i;

	auto swapp=[&](int i,int j){
		std::swap(p[i],p[j]);
		ppos[p[i]]=i;
		ppos[p[j]]=j;
	};

	for(int i=1;i<(1<<k);++i){
		int x=a[i-1] xor target[i-1];
		if(x){
			a[i-1]^=x;
			a[i]^=x;

			int m=i,n=i-1;
			for(;;){
				if((p[m] xor q[m])==a[m])
					break;
				if((p[n] xor q[m])==a[m]){
					swapp(m,n);
					assert((p[m] xor q[m])==a[m]);
					assert((p[n] xor q[n])==a[n]);
					break;
				}
				int t=ppos[a[m] xor q[m]];
				assert(t!=m and t!=n);

				swapp(m,t);
				assert((p[m] xor q[m])==a[m]);
				m=t;
				std::swap(q[m],q[n]);
			}
		}

		assert(std::equal(begin(a),begin(a)+i,begin(target)));
	}

	assert(a==target);
	std::cout<<"Shi\n";
	for(int x:p)std::cout<<x<<' ';
	std::cout<<'\n';
	for(int x:q)std::cout<<x<<' ';
	std::cout<<'\n';
}