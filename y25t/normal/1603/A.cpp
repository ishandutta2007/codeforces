#include<bits/stdc++.h>
#define ll long long
#define N 100005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ll tmp=1;
		bool flg=1;
		for(int i=1;i<=n;i++){
			if(tmp<=1e9)
				tmp=tmp/std::__gcd(tmp,(ll)i+1)*(i+1);
			scanf("%d",&a[i]);
			if(a[i]%tmp==0)
				flg=0;
		}
		puts(flg?"YES":"NO");
	}
}