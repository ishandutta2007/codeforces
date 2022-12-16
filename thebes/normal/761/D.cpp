#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5;
int n, l, r, arr[MN], idx[MN], x, i, j, last=-1<<30, ans[MN];

int main(){
	for(scanf("%d%d%d",&n,&l,&r),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		idx[x] = i;
	}
	for(i=1;i<=n;i++){
		int c = idx[i];
		if(r-arr[c]<=last){
			printf("-1\n");
			return 0;
		}
		if(l-arr[c]>last){
			ans[c] = l;
			last = l-arr[c];
		}
		else{
			x=last+arr[c]+1;
			ans[c] = x; last++;
		}
	}
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}