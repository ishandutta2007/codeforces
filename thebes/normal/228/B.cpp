#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

bitset<400> a[200], b[200];
int main(){
	int N, M, A, B, i, j, x=0, y=0, ans=0;
	for(scanf("%d%d",&N,&M),i=1;i<=N;i++){
		for(getchar(),j=1;j<=M;j++)
			if(getchar()=='1') a[i+100][j+100]=1;
	}
	for(scanf("%d%d",&A,&B),i=1;i<=A;i++){
		for(getchar(),j=1;j<=B;j++)
			if(getchar()=='1') b[i+100][j+100]=1;
	}
	for(i=-51;i<=51;i++){
		for(j=-51;j<=51;j++){
			int count = 0;
			for(int w=1;w<=N;w++){
				for(int y=1;y<=M;y++)
					if(a[w+100][y+100]&&b[w+i+100][y+j+100]) count++;
			}
			if(count>ans){
				ans = count;
				x=i; y=j;
			}
		}
	}
	printf("%d %d\n",x,y);
	return 0;
}