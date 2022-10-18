#include<bits/stdc++.h>
#define N 15

int T;

char s[N];
int a[N];

int ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		ans=10;
		for(int l=0;l<(1<<10);l++){
			for(int i=1;i<=10;i++)
				a[i]=(l>>(i-1))&1;
			bool flg=1;
			for(int i=1;i<=10;i++)
				if(s[i]!='?'&&s[i]!=a[i]+'0')
					flg=0;
			if(!flg)
				continue;
			int tmp=0;
			for(int i=1;i<=10;i++){
				if(i&1)
					tmp+=a[i];
				else
					tmp-=a[i];
				if((10-i+1)/2<tmp)
					ans=std::min(ans,i);
				if((10-i)/2<-tmp)
					ans=std::min(ans,i);
			}
		}
		printf("%d\n",ans);
	}
}