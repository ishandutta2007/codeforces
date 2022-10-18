#include<bits/stdc++.h>

int T;

int n;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int res=0;
		int lst=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			res+=x&&!lst;
			lst=x;
		}
		res=std::min(res,2);
		printf("%d\n",res);
	}
}