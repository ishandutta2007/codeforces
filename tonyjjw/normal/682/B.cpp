#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100000 + 10;

int N;
int A[MN];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	sort(A,A+N);
	int p=0;
	int ans;
	for(ans=1;;ans++){
		while(p<N && A[p]<ans) p++;
		if(p==N) return !printf("%d\n",ans);
		p++;
	}
	
	return 0;
}