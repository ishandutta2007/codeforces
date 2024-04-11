#include<cstdio>
#include<vector>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 105

int n;

std::vector<pii> A,B;

inline void ans(int x,int y,int z){
	printf("%d %d %d\n",x,y,z);
	fflush(stdout);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)%2==0)
				A.push_back(mp(i,j));
			else
				B.push_back(mp(i,j));
	for(int i=1;i<=n*n;i++){
		int x;
		scanf("%d",&x);
		if(x!=1){
			if(A.size()){
				ans(1,A.back().fir,A.back().sec);
				A.pop_back();
			}
			else{
				ans(2^3^x,B.back().fir,B.back().sec);
				B.pop_back();
			}
		}
		else{
			if(B.size()){
				ans(2,B.back().fir,B.back().sec);
				B.pop_back();
			}
			else{
				ans(3,A.back().fir,A.back().sec);
				A.pop_back();
			}
		}
	}
}