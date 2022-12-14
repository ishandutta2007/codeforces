#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int factor[100100];
int cnt[100100];

vector<int> oddp;

vector<int> nums[100100];
bool used[100100];


int main(){
	for(int i=0;i<100100;i++) factor[i]=-1;
	for(int i=2;i<100100;i++){
		if(factor[i]==-1){
			for(int j=2;i*j<100100;j++){
				factor[i*j]=i;
			}
		}
	}
	int N;
	scanf("%d",&N);
	if(N<=3){
		printf("0\n");
		return 0;
	}
	for(int i=2;i<=N;i++){
		if(factor[i]==-1){
			if(i*2>N) continue;
			else cnt[i]++;
		}
		else cnt[factor[i]]++;
	}
	int ans=0;
	for(int i=2;i<=N;i++){
		if(factor[i]==-1){
			ans+=cnt[i]/2;
			if(cnt[i]%2==1){
				oddp.push_back(i);
			}
		}
	}
	ans+=oddp.size()/2;
	printf("%d\n",ans);
	for(int i=(int)oddp.size()-1;i>=1;i-=2){
		int p1=oddp[i];
		int p2=oddp[i-1];
		used[p1*2]=true;
		used[p2*2]=true;
		printf("%d %d\n",p1*2,p2*2);
	}
	for(int i=2;i<=N;i++){
		if(factor[i]==-1){
			if(i*2>N) continue;
			else nums[i].push_back(i);
		}else if(used[i]==false) nums[factor[i]].push_back(i);
	}
	for(int i=2;i<=N;i++){
		for(int j=0;j<(int)nums[i].size()-1;j+=2){
			printf("%d %d\n",nums[i][j],nums[i][j+1]);
		}
	}
	return 0;
}