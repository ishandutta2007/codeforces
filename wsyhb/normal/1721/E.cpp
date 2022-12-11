#include<bits/stdc++.h>
using namespace std;
const int max_len=1e6+20;
char s[max_len],t[15];
int nxt[max_len],fath[max_len],to[max_len][26]; // to: 100 MB 
int main()
{
	int q;
	scanf("%s%d",s+1,&q);
	int len=strlen(s+1);
	for(int i=2,j=0;i<=len;++i)
	{
		while(j>0&&s[i]!=s[j+1])
			j=nxt[j];
		j+=(s[i]==s[j+1]);
		fath[i]=nxt[i]=j;
		to[i-1][s[i]-'a']=i-1;
		for(int k=0;k<26;++k)
			to[i][k]=to[j][k];
	}
	while(q--)
	{
		scanf("%s",t+1);
		int old=to[len][t[1]-'a'];
		int len_t=strlen(t+1);
		for(int i=1;i<=len_t;++i)
		{
			to[len+i-1][t[i]-'a']=len+i-1;
			int res=to[fath[len+i-1]][t[i]-'a'];
			char ch=(res+1<=len?s[res+1]:t[(res+1)-len]);
			res+=(ch==t[i]);
			fath[len+i]=res;
			for(int k=0;k<26;++k)
				to[len+i][k]=to[res][k];
			printf("%d%c",res," \n"[i==len_t]);
		}
		to[len][t[1]-'a']=old;
	}
	return 0;
}