#include<bits/stdc++.h>
#define N 15

int T;

int pw[N];

int n,a[N];

int main(){
	pw[0]=1;
	for(int i=1;i<=10;i++)
		pw[i]=3*pw[i-1];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		bool flg=0;
		for(int l=1;l<pw[n];l++){
			int x=0,y=0;
			for(int i=1;i<=n;i++){
				int o=l/pw[i-1]%3;
				if(o==1)
					x+=a[i];
				else if(o==2)
					y+=a[i];
			}
			if(x==y)
				flg=1;
		}
		puts(flg?"YES":"NO");
	}
}