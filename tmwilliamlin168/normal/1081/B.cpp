#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
const int MAXN = 1e5+7;
int ans[MAXN];
pii A[MAXN];
int main(){
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++){
		int ai; scanf("%d", &ai);
		A[i] = mp(ai, i+1);
	}
	sort(A, A+n);
	int cur=0, hat=1;
	while(cur<n){
		for(int i=cur; i<cur+(n-A[cur].first); i++){
			if(i>=n || A[i].first!=A[cur].first){
				printf("Impossible");
				return 0;
			}
			ans[A[i].second]=hat;
		}
		hat++;
		cur = cur+ (n - A[cur].first);
	}
	printf("Possible\n");
	for(int i=1; i<=n; i++){
		printf("%d ", ans[i]);
	}
}