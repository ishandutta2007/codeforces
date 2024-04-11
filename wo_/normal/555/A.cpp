#include<cstdio>
#include<vector>

using namespace std;

vector<int> vecs[100100];

int N,K;

int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<K;i++){
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			int x;
			scanf("%d",&x);
			vecs[i].push_back(x);
		}
	}
	int cnt=0;
	for(int i=0;i<K;i++){
		if(vecs[i][0]==1){
			for(int j=1;j<vecs[i].size();j++){
				if(vecs[i][j]!=vecs[i][j-1]+1) break;
				cnt++;
			}
		}
	}
	int ans=2*N-1-K-2*cnt;
	printf("%d\n",ans);
	return 0;
}