#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100 + 5;

int N;
int A[MN];
char buf[200];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&A[i]);
	scanf("\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<200;j++) buf[j]=0;
		fgets(buf, 150, stdin);
		for(int j=0;j<150;j++){
			if(buf[j]=='a' || buf[j]=='e' || buf[j]=='i' || buf[j]=='o' || buf[j]=='u' || buf[j]=='y'){
				A[i]--;
			}
		}
		if(A[i]!=0){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}