#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
#define max_n 100
int f[max_n+2][max_n+2][max_n+2],comb[max_n+2][max_n+2];
int main(){
	int n,m,k,mod;
	scanf("%d%d%d%d",&n,&m,&k,&mod);
	comb[0][0]=1;
	for(int i=1; i<=n; ++i){
		comb[i][0]=comb[i][i]=1;
		for(int j=1; j<i; ++j)
			(comb[i][j]=comb[i-1][j]+comb[i-1][j-1])>=mod&&(comb[i][j]-=mod);
	}
	for(int i=n+1; i; --i){
		f[i][0][0]=1;
		vector<int>vec[max_n+1];
		for(int j=0; j<=n; ++j)
			for(int l=0; l<=j; ++l)
				if(f[i+1][j][l])
					vec[j].push_back(l);
		for(int j=0; j<=n; ++j)
			if(!vec[j].empty())
				for(int l=0; j+l<=n; ++l)
					if(!vec[l].empty())
						for(auto x:vec[j])
							for(auto y:vec[l]){
								int&t=f[i][j+l+1][x+y+int(i==m)];
								t=(t+ll(comb[j+l][j])*f[i+1][j][x]%mod*f[i+1][l][y])%mod;
							}
	}
	printf("%d\n",f[1][n][k]);
	return 0;
}