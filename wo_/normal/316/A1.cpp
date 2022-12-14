#include<cstdio>
#include<cstring>

using namespace std;

char ch[100100];
bool appear[10];

int main()
{
	scanf("%s",ch);
	int ln=strlen(ch);
	for(int i=0;i<10;i++) appear[i]=false;
	for(int i=0;i<ln;i++)
	{
		if('A'<=ch[i]&&ch[i]<='J')
		{
			appear[ch[i]-'A']=true;
		}
	}
	int cnt=0;
	for(int i=0;i<10;i++) if(appear[i]) cnt++;
	int ans=1;
	if('A'<=ch[0]&&ch[0]<='J')
	{
		ans*=9;
	}
	else if(cnt!=0) ans*=10;
	for(int i=0;i<cnt-1;i++) ans*=(9-i);
	
	int cnt_q=0;
	for(int i=0;i<ln;i++) if(ch[i]=='?') cnt_q++;
	if(ch[0]=='?')
	{
		cnt_q--;
		ans*=9;
	}
	printf("%d",ans);
	for(int i=0;i<cnt_q;i++) printf("0");
	printf("\n");
	return 0;
}