#include<bits/stdc++.h>

int T;

char s[100];

int main(){
	scanf("%d",&T);
	while(T--){
		bool flg=0;
		int x=2;
		puts("1 1");
		fflush(stdout);
		scanf("%s",s+1);
		if(s[1]=='D'&&s[3]=='n')
			continue;
		for(int i=1;i<=8&&!flg;i++)
			for(int j=x;j<=16+x;j++){
				printf("%d %d\n",i,(j-1)%8+1);
				fflush(stdout);
				scanf("%s",s+1);
				if(s[1]=='D'){
					if(s[3]=='n')
						flg=1;
					else
						x=(j-1)%8+1;
					break;
				}
			}
	}
}