#include<cstdio>
#include<cstring>
#include<algorithm>
#define ri register int
#define N 200005

int T;

char s[N];
int n;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=n;
		for(ri i=0;i<=9;i++)
			for(ri j=0;j<=9;j++){
				int flg=0,cnt=0;
				for(ri k=1;k<=n;k++)
					if(s[k]==(flg?i:j)+'0'){
						flg^=1;
						cnt++;
					}
				if(i!=j&&cnt%2==1)
					cnt--;
				ans=std::min(ans,n-cnt);
			}
		printf("%d\n",ans);
	}
}