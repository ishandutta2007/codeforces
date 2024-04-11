#include<cstdio>
#define N 200005

int n;
char s[N];

int cnt,tmp;

int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n/2;i++)
		if(s[i]=='?')
			cnt++;
		else
			tmp+=s[i]-'0';
	for(int i=n/2+1;i<=n;i++)
		if(s[i]=='?')
			cnt--;
		else
			tmp-=s[i]-'0';
	if(cnt/2*9==-tmp)
		printf("Bicarp");
	else
		printf("Monocarp");
}