#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;

const int maxn=100007;
int n,k,A,X[maxn],C[maxn];
long long ans=0;

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i){
		scanf("%d",&X[i]);
	}
	scanf("%d",&A);
	for (int i=1;i<=n;++i){
		scanf("%d",&C[i]);
	}
	for (int i=1;i<=n;++i){
		q.push(C[i]);
		while (k<X[i]){
			if (q.empty()){
				printf("-1");
				return 0;
			}
			k+=A, ans+=q.top(), q.pop();
		}
	}
	printf("%I64d",ans);
	return 0;
}