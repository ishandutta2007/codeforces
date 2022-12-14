#include<iostream>
#include<vector>
#include<bitset>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int constexpr END_VAL=200001,END_GVAL=100;

	std::bitset<END_VAL> moves{};
	// 0 for a noncomposite number, a nontrivial factor otherwise
	std::vector<int> factor(END_VAL);
	for(int i=2;i*i<END_VAL;++i)
		if(factor[i]==0){
			for(int j=i*i;j<END_VAL;j+=i)
				factor[j]=i;
		}

	for(int i=2;i<END_VAL;++i)
		if(factor[i]==0||factor[i/factor[i]]==0){
			moves[i]=1;
		}

	int nrow,forbidden_move;std::cin>>nrow>>forbidden_move;
	moves[forbidden_move]=0;

	std::vector<std::bitset<END_VAL>> f(END_GVAL);
	std::vector<int> grundy(END_VAL);
	for(int i=0;i<END_VAL;++i,moves<<=1){
		while(f[grundy[i]][i])++grundy[i];
		f[grundy[i]]|=moves;
		if(grundy[i]>=END_VAL)return 1;
	}

	int grundy_of_game=0;
	for(int _=nrow;_-->0;){
		int a,b,c;std::cin>>a>>b>>c;
		grundy_of_game^=grundy[b-a-1]^grundy[c-b-1];
	}
	std::cout<<(grundy_of_game!=0?"Alice\nBob\n":"Bob\nAlice\n");
}