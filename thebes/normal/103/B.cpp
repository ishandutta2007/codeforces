#include <bits/stdc++.h>
using namespace std;

int ds[101], N, M, i, j, x, y;
int ld(int x){return ds[x]=(ds[x]==x)?x:ld(ds[x]);}

int main(){
	for(i=1;i<=100;i++) ds[i]=i;
	for(scanf("%d%d",&N,&M),i=0;i<M;i++){
		scanf("%d%d",&x,&y);
		ds[ld(x)] = ds[ld(y)];
	}
	for(i=1;i<=N;i++){
		if(ld(1)!=ld(i)){
			printf("NO\n");
			return 0;
		}
	}
	printf("%s\n",(M==N)?"FHTAGN!":"NO");
	return 0;
}