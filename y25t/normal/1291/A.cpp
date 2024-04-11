#include<cstdio>
#define N 30005

int T;

int n;
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		int tmp=0;
		bool flg=0;
		for(int i=1;i<=n;i++)
			if((s[i]-'0')&1)
				if(tmp){
					printf("%d%d\n",tmp,s[i]-'0');
					flg=1;
					break;
				}
				else
					tmp=s[i]-'0';
		if(!flg)
			printf("-1\n");
	}
}