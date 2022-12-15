#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 105;
int T, N, K, i, cnt, arr[MN];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&K);
		for(i=1;i<=N;i++){
			scanf("%d",&arr[i]);
		}
		cnt = 0;
		for(i=1;i<N;i++){
			if(arr[i]!=arr[i+1]) cnt++;
		}
		if(!cnt) printf("1\n");
		else if(K==1) printf("-1\n");
		else{
			int res = ceil(cnt/(double)(K-1));
			printf("%d\n",res);
		}
	}
	return 0;
}