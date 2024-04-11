#include<cstdio>
#include<cstring>
#define N 105

int T;

char s[N],t[N],p[N];

int cnt[30];

int main(){
	scanf("%d",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		scanf("%s%s%s",s+1,t+1,p+1);
		bool flg=0;
		int ss=strlen(s+1),tt=strlen(t+1),pp=strlen(p+1);
		for(int i=1;i<=ss;i++)
			cnt[s[i]-'a'+1]++;
		for(int i=1;i<=tt;i++)
			cnt[t[i]-'a'+1]--;
		for(int i=1;i<=pp;i++)
			cnt[p[i]-'a'+1]++;
		for(int i=1;i<=26;i++)
			if(cnt[i]<0)
				flg=1;
		if(flg){
			printf("NO\n");
			continue;
		}
		int tmp=1;
		for(int i=1;i<=tt;i++)
			if(t[i]==s[tmp])
				tmp++;
		if(tmp<=ss)
			printf("NO\n");
		else
			printf("YES\n");
	}
}