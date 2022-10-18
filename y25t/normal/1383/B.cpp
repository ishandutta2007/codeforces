#include<cstdio>

int T;

int n;

int cnt[35];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			for(int j=0;j<=30;j++)
				if(a&(1<<j))
					cnt[j]++;
		}
		bool flg=0;
		for(int i=30;i>=0;i--)
			if(cnt[i]&&(cnt[i]&1)){
				flg=1;
				if((cnt[i]>>1&1)&&(n&1))
					puts("LOSE");
				else
					puts("WIN");
				break;
			}
		if(!flg)
			puts("DRAW");
		for(int i=0;i<=30;i++)
			cnt[i]=0;
	}
}