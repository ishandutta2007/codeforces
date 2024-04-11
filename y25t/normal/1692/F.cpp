#include<bits/stdc++.h>
#define N 200005

int T;

int n,a[N];

int cnt[10],c[10];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),a[i]%=10,cnt[a[i]]++;
		bool flg=0;
		for(int i=0;i<10;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++) if((i+j+k)%10==3){
			c[i]++,c[j]++,c[k]++;
			if(c[i]<=cnt[i]&&c[j]<=cnt[j]&&c[k]<=cnt[k])
				flg=1;
			c[i]=c[j]=c[k]=0;
		}
		puts(flg?"YES":"NO");
		for(int i=1;i<=n;i++)
			cnt[a[i]]--;
	}
}