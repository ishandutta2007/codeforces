#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int N, ans=1<<30, i, arr[MN], ps[MN], ss[MN], x;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d",&arr[i]);
		ps[i]=ps[i-1]+(arr[i]>=0);
	}
	for(i=N;i>=1;i--)
		ss[i]=ss[i+1]+(arr[i]<=0);
	for(i=2;i<=N;i++){
		x = ps[i-1]+ss[i];
		ans = min(ans,x);
	}
	printf("%d\n",ans);
	return 0;
}