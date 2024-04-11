#include<bits/stdc++.h>

int T;

int n,x;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		int res=0;
		for(int i=1;i<=n;i++){
			int y;
			scanf("%d",&y);
			res=std::max(res,y|x);
		}
		printf("%d\n",res);
	}
}