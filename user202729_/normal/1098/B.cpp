// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

auto transpose(std::vector<std::string> const& data){
	std::vector<std::string> dataTrans(data[0].size(), std::string(data.size(), 0));
	for(int row=0;row<(int)data.size();++row)
		for(int col=0;col<(int)data[0].size();++col) dataTrans[col][row]=data[row][col];
	return dataTrans;
}

std::array<char, 4> const characters{'A', 'C', 'T', 'G'};

struct SolveResult{ int numChange; std::vector<std::string> data; };
SolveResult solve(std::vector<std::string> data){
	// assumes each row has period 2.
	SolveResult result;
	result.numChange=INT_MAX;

	using P=std::array<char, 2>;
	std::vector<P> candidate(data.size()), resultCandidate(data.size());

	for(auto a: characters)for(auto b: characters) { // 6*
		if(a==b) break;

		// result first line has pattern ababab... or bababa...
		std::vector<char> rest(begin(characters),end(characters));
		rest.erase(std::find(begin(rest),end(rest), a));
		rest.erase(std::find(begin(rest),end(rest), b));
		auto const c=rest[0], d=rest[1];

		int numChange=0;

		struct MatchResult{ P order; int numChange; };
		auto const match=[](std::string const& row, P characters)->MatchResult{
			auto const match1=[&row](P characters)->int{
				int numChange=0;
				for(int col=0;col<(int)row.size();++col) numChange+=characters[col&1]!=row[col];
				return numChange;
			};

			auto x=match1(characters);
			P charactersSwapped{{characters[1], characters[0]}}; auto y=match1(charactersSwapped);
			return x<y ? MatchResult{characters, x} : MatchResult{charactersSwapped, y};
		};
		for(int row=0;row<(int)data.size();++row) {
			auto const [candidateData, numChangeRow]=match(data[row], row&1 ?  P{{c, d}} : P{{a, b}});
			candidate[row]=candidateData; numChange+=numChangeRow;
		}
		if(numChange<result.numChange){ std::swap(resultCandidate, candidate); result.numChange=numChange; }
	}

	result.data=std::move(data);
	for(int row=0;row<(int)result.data.size();++row) 
		for(int col=0;col<(int)result.data[row].size();++col) 
			result.data[row][col]=resultCandidate[row][col&1];

	return result;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numRow, numCol; std::cin>>numRow>>numCol;
	std::vector<std::string> data(numRow);
	for(auto & row: data){
		row.reserve(numCol); std::cin>>row;
	}

	auto [numChange, result]=solve(data);
	auto [numChange1, result1]=solve(transpose(data));
	if(numChange1<numChange) { numChange=numChange1; result=transpose(result1); }

	for(auto const& row: result) std::cout<<row<<'\n';
}