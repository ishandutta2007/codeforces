#include <bits/stdc++.h>
using namespace std;

const int MN = 105;
int n, m, k, sz[MN], i, tot;

int main(){
	for(scanf("%d%d%d",&n,&m,&k),i=1;i<=n;i++)
		scanf("%d",&sz[i]);
	sort(sz+1,sz+n+1,[](int i,int j){return i>j;});
	m -= k-1;
	if(m<=1){
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n;i++){
		m -= (sz[i]-1);
		if(m <= 1){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}