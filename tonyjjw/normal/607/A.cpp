#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100000 + 5;

pii A[MN];
int num[MN];

int N;

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d%d",&A[i].first,&A[i].second);
	sort(A,A+N);
	for(int i=0,j=0;j<N;j++){
		i = lower_bound(A,A+N,pii(A[j].first-A[j].second,-1)) - A;
		if(i==0){
			num[j]=j;
		}
		else{
			num[j]=(j-i)+num[i-1];
		}
	}
	int ans = N;
	for(int i=0;i<N;i++){
		if(ans > num[i] + N-1-i){
			ans = num[i] + N-1-i;
		}
	}
	printf("%d\n",ans);
	return 0;
}