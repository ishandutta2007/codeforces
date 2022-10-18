#include<bits/stdc++.h>
#define N 200005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int lst=0;
		long long res=0;
		for(int i=2;i<=n;i++) if(a[i]==a[i-1]){
			if(lst){
				if(lst==i-1)
					res++,lst=i,i++;
				else
					res+=i-lst-1,lst=i-1;
			}
			else
				lst=i;
		}
		printf("%lld\n",res);
	}
}