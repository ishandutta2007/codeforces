// problem-url: https://codeforces.com/contest/1089/submit/C
#define NDEBUG 1
#include<bits/stdc++.h>
int main(){
	std::ios::sync_with_stdio(0);
	int nnode,npath;std::cin>>nnode>>npath;

	std::vector<std::vector<int>> dist(nnode,std::vector<int>(nnode,INT_MAX/2));

	for(int i=npath;i--;){
		int pathlen;std::cin>>pathlen;
		int last;std::cin>>last;--last;
		for(int i=pathlen-1;i--;){
			int x;std::cin>>x;--x;
			dist[last][x]=1;
			last=x;
		}
	}

	// complete the dist array
	for(int i=0;i<nnode;i++) dist[i][i]=0;
	for(int i=0;i<nnode;i++) for(int j=0;j<nnode;j++) dist[i][j]=std::min(dist[i][j],dist[j][i]);

	// floyd
	for(int m=0;m<nnode;m++)
	for(int i=0;i<nnode;i++) for(int j=0;j<nnode;j++) dist[i][j]=std::min(dist[i][j],
			dist[i][m]+dist[m][j]
			);

	for(int i=0;i<nnode;i++) for(int j=0;j<nnode;j++) assert(dist[i][j]<=nnode); // cactuses (cacti?) are connected

	for(int test=nnode;test--;){

		std::vector<int> cand(nnode);
		std::iota(begin(cand),end(cand),0);

		while(true){
			auto const leftifguess=[&](int guess,int go)->std::vector<int>{
				assert(dist[guess][go]<=1);
				if(go==guess) return {guess};
				assert(dist[guess][go]==1);

				std::vector<int> re;
				for(int x:cand) if(dist[x][go]<dist[x][guess]) re.push_back(x);
				return re;
			};

			auto const countleftifguess=[&](int guess,int go)->int{
				assert(dist[guess][go]<=1);
				if(go==guess) return 1;
				assert(dist[guess][go]==1);

				int re=0;
				for(int x:cand) if(dist[x][go]<dist[x][guess]) re++;
				return re;
			};

			auto const guessscore=[&](int guess){
				int re=0;
				for(int go=0;go<nnode;go++) if(dist[guess][go]<=1)
					re=std::max(re,countleftifguess(guess,go));
				return re;
			};

			std::pair<int,int> minscore={INT_MAX,-1}; // the score is the remaining candidate size int the  worst case
			if(cand.size()==1){
				minscore={1,cand[0]};
			}else{
				for(int possibleguess=0;possibleguess<nnode;possibleguess++){
					minscore=std::min(minscore,std::make_pair(guessscore(possibleguess),possibleguess));
				}
			}

			int guess=minscore.second;
			assert(guess>=0);
			std::cout<<guess+1<<'\n';
			std::string response;std::cin>>response;
			if(response=="GO"){
				int go;std::cin>>go;--go;
				assert(dist[guess][go]==1);
				assert(cand.size()>=2); // otherwise FOUND must be the answer...
				cand=leftifguess(guess,go);
				assert(int(cand.size())<=minscore.first);
			}else{
				assert(response=="FOUND");
				break;
			}
		}
	}
}