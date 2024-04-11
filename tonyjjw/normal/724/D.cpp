#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100000 + 1;
const int S = 26;

char buf[MN];
char ans[MN];
int N, M, nn;
int A[MN];
vector<int> pos[S];

int main(){
	scanf("%d",&M);
	scanf("%s",buf);
	N = strlen(buf);
	for(int i=0;i<N;i++){
		pos[buf[i]-'a'].push_back(i);
	}
	for(int i=0;i<N;i++) A[i] = 1;
	for(int i=S-1; i>=0; i--){
		for(auto &idx: pos[i]) A[idx] = 0;
		int sum = 0;
		bool flag = false;
		for(int j=0;j<N;j++){
			sum += A[j];
			if(j-M >= 0) sum -= A[j-M];
			if(j >= M-1 && sum == 0){
				flag = true;
				break;
			}
		}
		if(!flag) continue;
		sum = 0;
		int p = 0;
		for(int j=0;j<N;j++){
			if(p < pos[i].size() && pos[i][p] == j){
				p++;
			}
			sum += A[j];
			if(j-M >= 0) sum -= A[j-M];
			if(j >= M-1 && sum == 0){
				sum++;
				A[pos[i][p-1]] = 1;
			}
		}
		break;
	}
	for(int i=0;i<N;i++) if(A[i]) ans[nn++] = buf[i];
	sort(ans, ans+nn);
	printf("%s\n",ans);
	return 0;
}