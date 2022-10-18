#include<bits/stdc++.h>

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int t=0,f=1;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(t>x)
				f=0;
			t=x;
		}
		puts(f?"NO":"YES");
	}
}