// This problem is not as hard (to me) as some older F problems... it's just hard to implement.
// Another [permutation-puzzle] problem: https://codeforces.com/problemset/problem/1044/E
//
// It took me too much time just to fix a typo (see diff for details). I don't know if looking at the code is faster than
// writing a test generator (which is what I've done)
// [REMINDER] I should write a test generator without check output correctness to see if there's any failed assertions first.

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<array>
#include<iostream>
#include<string>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		std::string out;
		int k;std::cin>>k;
		std::array<std::vector<int>,2> v;

		int emptycol;
		assert((emptycol=-1));

		for(auto& row:v){
			row.resize(k*2+1);
			for(unsigned col=0;col<row.size();++col){
				int& x=row[col];
				if(std::cin>>x){
					/* renumber cells such that the correct arrangement is

+------------------------------------------------------------------------------+
| 3*k+2 3*k+3 3*k+4 ...   4*k   0     1     2     3     ...   k-1   k     k+1  |
|       +--------------------------+      +----------------------------+       |
| 3*k+1 3*k   3*k-1 ...   2*k+3 2*k+2 2*k+1 2*k   2*k-1 ...   k+3   k+2   [E]  |
+------------------------------------------------------------------------------+
					*/
				    if(x<=2*k+1){
					  x=3*k+1+x;
					  if(x>4*k) x-=4*k+1;
				    }else{
					  x=(3*k+1)-(x-(2*k+2));
				    }
				}else{
					std::cin.clear();
					char c;std::cin>>c;
					assert(c=='E');
					x=-1;
					emptycol=col;
				}
			}
		}

		auto& row_contain_empty=v[1][emptycol]<0 ? v[1] : v[0];
		while((int)emptycol<2*k){
			out+='r';
			std::swap(row_contain_empty[emptycol],row_contain_empty[emptycol+1]);
			++emptycol;
		}

		if(v[0].back()<0){
			out+='d';
			std::swap(v[0].back(),v[1].back());
		}
		assert(v[1].back()<0);

		std::vector<int> newp;newp.reserve(4*k+1);
		newp.insert(end(newp),begin(v[0])+k-1,end(v[0]));
		newp.insert(end(newp),++v[1].rbegin(),v[1].rend());
		newp.insert(end(newp),begin(v[0]),begin(v[0])+k-1);
		assert(newp.size()==unsigned(4*k+1));

		v[0].clear(); v[1].clear();

		int start=0;
		// newp[x-start] = new index of block at (home of block with new index x)
		// wraparound

		int i=4*k; // such that block i..4*k are cyclically continuous
		{
			auto posi=int(std::find(begin(newp),end(newp),i)-begin(newp));
			std::rotate(begin(newp),begin(newp)+posi+1,end(newp));
			start=(int)newp.size()-(posi+1);
		}
		assert(newp.back()==i);

		auto const macroA=[&](){
			// macro A: move block at (new) position 0,1,2... to 4*k,0,1,...
			out+='A';
			++start;
			if(start==(int)newp.size()) start=0;
		};

		auto const macroB=[&](){
			// macro B: move block at (new) position 0,1,2 to 1,2,0
			out+='B';
			std::swap(newp[start],newp[(start+1)%newp.size()]);
			std::swap(newp[start],newp[(start+2)%newp.size()]);
		};

		while(i>2){
			assert(newp.back()==(int)newp.size()-1);
			assert(newp[i]==i);

			int const j=i-1;
			auto posj=int(std::find(begin(newp),end(newp),j)-begin(newp));
			if(posj!=j){
				while(start!=std::max(0,posj-1))macroA();
				if(posj==0){ macroB();++posj; }

				while(posj<j){
					assert(start==posj-1);
					macroB();++posj;
					macroA();
				}
			}
			assert(newp[j]==j);
			i=j;
		}

		assert(newp[2]==2);
		if(newp[1]!=1){
			std::cout<<"SURGERY FAILED\n";
			continue;
		}

		assert(newp[0]==0);
		while(start!=0) macroA();

		std::cout<<"SURGERY COMPLETE\n"<<out<<'\n';
		{ // print macros
			//std::string LL(k,'l');
			//std::string RR(k,'r');

			std::cout<<"A ";
			for(int z=2*k;z--;) std::cout<<'l';
			std::cout<<'u';
			for(int z=2*k;z--;) std::cout<<'r';
			std::cout<<"d\n";


			std::cout<<"B ";
			for(int z=k;z--;) std::cout<<'l';

			std::cout<<'u';
			for(int z=k;z--;) std::cout<<'l';
			std::cout<<'d';
			for(int z=k;z--;) std::cout<<'r';

			std::cout<<'u';
			for(int z=k;z--;) std::cout<<'r';
			std::cout<<'d';
			for(int z=k;z--;) std::cout<<'l';

			for(int z=k;z--;) std::cout<<'l';
			std::cout<<'u';
			for(int z=k;z--;) std::cout<<'r';
			std::cout<<'d';

			for(int z=k;z--;) std::cout<<'r';
			std::cout<<'u';
			for(int z=k;z--;) std::cout<<'l';
			std::cout<<'d';

			for(int z=k;z--;) std::cout<<'r';
			std::cout<<'\n';
		}
		std::cout<<"DONE\n";
	}
}