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
	int m; std::cin>>m;

	std::vector a(n, std::vector<int>(n));
	for(auto& row: a) for(auto& cell: row) std::cin>>cell;

	int const ROWS=0, COLS=1, VAL=2; // axis/dimension name
	using P=std::array<int, 3>;
	std::array<P, 4> points{};
	// (+dimension 1, +dimension 2, +dimension 3, root)
	for(int i=0; i<3; ++i) points[i][i]=1;
	P& root=points[3];

	for(int _=0; _<m; ++_){
		char c; std::cin>>c;
		switch(c){
			case 'R': root[COLS]++; break;
			case 'L': root[COLS]--; break;
			case 'D': root[ROWS]++; break;
			case 'U': root[ROWS]--; break;
			case 'I': for(auto& point: points) std::swap(point[VAL], point[COLS]); break;
			case 'C': for(auto& point: points) std::swap(point[VAL], point[ROWS]); break;
			default: assert(false); __builtin_unreachable();
		}
	}

	std::vector result(n, std::vector<int>(n));
	for(int row=0; row<n; ++row)
		for(int col=0; col<n; ++col){
			int val=a[row][col]-1;
			P resultingPoint;
			for(int i=0; i<3; ++i){
				resultingPoint[i]=
					(root[i]+
					 points[0][i]*row+
					points[1][i]*col+
					points[2][i]*val)%n;
				if(resultingPoint[i]<0) resultingPoint[i]+=n;
			}

			result[resultingPoint[0]][resultingPoint[1]]=resultingPoint[2];
		}

	for(int row=0; row<n; ++row){
		for(int col=0; col<n; ++col){
			std::cout<<result[row][col]+1<<' ';
		}
		std::cout<<'\n';
	}
	std::cout<<'\n';

}