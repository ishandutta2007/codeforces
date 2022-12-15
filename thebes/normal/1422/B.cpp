#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second

const int MN = 105;
int T, N, M, i, j, a[MN][MN];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		for(i=1;i<=N;i++){
			for(j=1;j<=M;j++){
				scanf("%d",&a[i][j]);
			}
		}
		long long ans = 0;
		for(i=1;i<=N-i+1;i++){
			for(j=1;j<=M-j+1;j++){
				vi vec;
				vec.push_back(a[i][j]);
				if(N-i+1!=i){
					if(M-j+1!=j){
						vec.push_back(a[N-i+1][M-j+1]);
					}
					vec.push_back(a[N-i+1][j]);
				}
				if(M-j+1!=j) vec.push_back(a[i][M-j+1]);
				sort(vec.begin(),vec.end());
				int mid = (int)vec.size()/2;
				for(auto v : vec)
					ans += abs(vec[mid]-v);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}