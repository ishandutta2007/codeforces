#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--){
		int numProblem; std::cin>>numProblem;
		double efficiency, time; std::cin>>efficiency>>time;
		struct problem{int difficulty, score;};
		std::vector<problem> problems(numProblem);
		for(auto &[difficulty, score]: problems) std::cin>>difficulty>>score;
		std::sort(begin(problems),end(problems),[&](auto one, auto two){
			return one.difficulty>two.difficulty;
		}); // problems should be done int decreasing difficulty order

		std::vector<double> pow09(numProblem+1);
		pow09[0]=1;
		for(int i=1;i<(int)pow09.size();++i) pow09[i]=pow09[i-1]*0.9;

		std::vector<std::vector<double>> f(1, std::vector<double>(1, 0));
		// f[number of problems chosen][sum of scores]=minimum value of X
		for(auto [difficulty, score]: problems){
			f.resize(f.size()+1);
			for(auto numChosen=f.size()-1; numChosen--;){
				f[numChosen+1].resize(std::max(f[numChosen+1].size(),
							f[numChosen].size()+score), 1e18);

				for(int curScore=0;curScore<(int)f[numChosen].size();++curScore) {
					if(f[numChosen][curScore]<1e18){
						f[numChosen+1][curScore+score]=std::min(f[numChosen+1][curScore+score],
								f[numChosen][curScore]+difficulty/pow09[numChosen+1]);
					}
				}
			}
		}

		int result=0;
		for(auto numChosen=f.size(); numChosen--;){
			for(int score=0;score<(int)f[numChosen].size();++score) {
				auto const x=f[numChosen][score];
				if(x<1e18 and (x<=time-numChosen*10 or (
								x*efficiency>=1 and
								2*std::sqrt(x/efficiency)-1/efficiency<=time-numChosen*10
								)))
					result=std::max(result, score);
			}
		}
		std::cout<<result<<'\n';
	}
}