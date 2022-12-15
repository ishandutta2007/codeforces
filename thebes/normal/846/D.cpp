#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> T;
const int MN = 1005;
int p[MN][MN], d[MN][MN], n, m, k, q, i, j;
T arr[MN*MN];

int main(){
	for(scanf("%d%d%d%d",&n,&m,&k,&q),i=1;i<=q;i++){
		int x, y, z;
		scanf("%d%d%d",&x,&y,&z);
		arr[i]={x,y,z};
	}
	sort(arr+1, arr+q+1, [](T i,T j){return(get<2>(i)<get<2>(j));});
	int lo = 1, hi = q+1;
	while(lo < hi){
		int mid = (lo+hi)/2;
		for(j=1;j<=mid;j++){
			int x=get<0>(arr[j]),y=get<1>(arr[j]);
			d[x][y]++; d[x+k][y]--; d[x][y+k]--; d[x+k][y+k]++;
		}
		bool flag=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				p[i][j]=d[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
				if(i>=k&&j>=k){
					if(p[i][j]==k*k)
						flag = 1;
				}
			}
		}
		if(flag) hi=mid;
		else lo=mid+1;
		memset(p, 0, sizeof(p));
		memset(d, 0, sizeof(d));
	}
	if(lo==q+1) printf("-1\n");
	else printf("%d\n",get<2>(arr[lo]));
	return 0;
}