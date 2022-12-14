#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int N,M,L;
int chk[7];

int digit(int n){
	if(n<7)return 1;
	return digit(n/7)+1;
}

int arr[7];
int ans;
void dfs(int n){
	if(n==L){
		int val=1;
		int a=0,b=0;
		for(int i=digit(N-1)-1;i>=0;i--){
			a+=val*arr[i];
			val*=7;
		}
		val=1;
		for(int i=L-1;i>=digit(N-1);i--){
			b+=val*arr[i];
			val*=7;
		}
		if(a<N && b<M) ans++;

		return;
	}
	for(int i=0;i<7;i++)if(!chk[i]){
		arr[n]=i;
		chk[i]=1;
		dfs(n+1);
		chk[i]=0;
		arr[n]=0;
	}
}

int main(){
	scanf("%d%d",&N,&M);
	L=digit(N-1)+digit(M-1);
	if(L>7){
		return !printf("0\n");
	}
	dfs(0);
	printf("%d\n",ans);
	return 0;
}