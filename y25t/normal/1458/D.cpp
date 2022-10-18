#include<cstdio>
#include<cstring>
#define N 500005

int T;

int n;
char s[N];

int cnt[N<<1][2];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=0;i<=(n<<1);i++)
			cnt[i][0]=cnt[i][1]=0;
		int p=n;
		for(int i=1;i<=n;i++){
			cnt[p][s[i]-'0']++;
			if(s[i]=='0')
				p--;
			else
				p++;
		}
		p=n;
		for(int i=1;i<=n;i++)
			if((cnt[p][0]&&cnt[p-1][1])||!cnt[p][1]){
				cnt[p][0]--;
				p--;
				printf("0");
			}
			else{
				cnt[p][1]--;
				p++;
				printf("1");
			}
		puts("");
	}
}