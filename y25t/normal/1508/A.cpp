#include<cstdio>
#include<algorithm>
#define N 400005

int T;

int n;
char s[3][N];

int cnt[3][2];

int a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s%s",&n,s[0]+1,s[1]+1,s[2]+1);
		for(int o=0;o<3;o++){
			cnt[o][0]=cnt[o][1]=0;
			for(int i=1;i<=2*n;i++)
				cnt[o][s[o][i]-'0']++;
		}
		int id;
		if((cnt[0][0]>=n)+(cnt[1][0]>=n)+(cnt[2][0]>=n)>=2)
			id=0;
		else
			id=1;
//		printf("&%d\n",id);
		int mx=n;
		for(int o=0,t=0;o<3;o++){
			if(cnt[o][id]<n||t==2)
				continue;
			t++;
			mx=std::max(mx,cnt[o][id]);
			for(int i=1,tmp=0;i<=2*n;i++)
				if(s[o][i]-'0'==(id^1))
					a[tmp]++;
				else
					tmp++;
		}
//		for(int i=0;i<=mx;i++)
//			printf("%d ",a[i]);
//		puts("");
		for(;a[0];a[0]--)
			putchar('0'+(id^1));
		for(int i=1;i<=mx;i++){
			putchar('0'+id);
			for(;a[i];a[i]--)
				putchar('0'+(id^1));
		}
		puts("");
	}
}