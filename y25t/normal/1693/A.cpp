#include<bits/stdc++.h>

int T;

int n;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long s=0;
		bool flg=1,f=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			s+=x;
			if(!s)
				f=1;
			if(s<0)
				flg=0;
			if(s>0&&f)
				flg=0;
		}
		if(s)
			flg=0;
		puts(flg?"Yes":"No");
	}
}