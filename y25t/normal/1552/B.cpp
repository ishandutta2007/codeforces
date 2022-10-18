#include<bits/stdc++.h>
#define N 50005

int T;

int n,a[N][5];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=0;j<5;j++)
				scanf("%d",&a[i][j]);
		int o=1;
		for(int i=2;i<=n;i++){
			int tmp=0;
			for(int j=0;j<5;j++)
				tmp+=a[o][j]<a[i][j];
			if(tmp<3)
				o=i;
		}
		bool flg=1;
		for(int i=1;i<=n;i++)
			if(i!=o){
				int tmp=0;
				for(int j=0;j<5;j++)
					tmp+=a[o][j]<a[i][j];
				if(tmp<3)
					flg=0;
			}
		printf("%d\n",flg?o:-1);
	}
}