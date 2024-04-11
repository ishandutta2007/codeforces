#include<bits/stdc++.h>
#define ll long long

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		ll ans=0;
		bool flg=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(i==1||i==n)
				continue;
			if(!(x&1)||(x>2&&n>3))
				flg=1;
			ans+=(x+1)>>1;
		}
		printf("%lld\n",flg?ans:-1);
	}
}