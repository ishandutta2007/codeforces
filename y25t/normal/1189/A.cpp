#include<cstdio>
#include<cstring>
#define N 105

int n;
char s[N];

int cnt[2];

int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		cnt[s[i]-'0']++;
	if(cnt[0]!=cnt[1])
		printf("1\n%s",s+1);
	else{
		s[n+1]=s[n];
		s[n]=' ';
		printf("2\n%s",s+1);
	}
}