#include <bits/stdc++.h>
using namespace std;
const int N=200050;
const int M=105;
int a[N],cnt[M];
int Get(int t){
	int ans=0;
	for(int i=1;i<M;i++){
		int take=min(cnt[i],t/i);
		t-=take*i;
		ans+=take;
	}
	return ans;
}
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i]);
		printf("%i\n",i-1-Get(m-a[i]));
		cnt[a[i]]++;
	}
	return 0;
}