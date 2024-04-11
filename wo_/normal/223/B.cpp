#include<cstdio>
#include<cstring>

using namespace std;

char ch[200200],target[200200];
int le[200200],ri[200200];

bool exi1[26],exi2[26];
int memo[26];

int main()
{
	scanf("%s%s",ch,target);
	int N=strlen(ch),M=strlen(target);
	memset(exi1,false,sizeof(exi1));
	memset(exi2,false,sizeof(exi2));
	for(int i=0;i<N;i++) exi1[ch[i]-'a']=true;
	for(int i=0;i<M;i++) exi2[target[i]-'a']=true;
	for(int i=0;i<26;i++) if(exi1[i]!=exi2[i]){printf("No\n");return 0;}
	int id=0;
	memset(ri,-1,sizeof(ri));
	for(int i=0;i<N;i++)
	{
		if(ch[i]==target[id])
		{
			ri[i]=id;
			id++;
		}
	}
	memset(le,-1,sizeof(le));
	id=M-1;
	for(int i=N-1;i>=0;i--)
	{
		if(ch[i]==target[id])
		{
			le[i]=id;
			id--;
		}
	}
	memset(memo,-1,sizeof(memo));
	for(int i=0;i<N;i++)
	{
		if(ri[i]!=-1) memo[ch[i]-'a']=ri[i];
		else ri[i]=memo[ch[i]-'a'];
	}
	memset(memo,-1,sizeof(memo));
	for(int i=N-1;i>=0;i--)
	{
		if(le[i]!=-1) memo[ch[i]-'a']=le[i];
		else le[i]=memo[ch[i]-'a'];
	}
	for(int i=0;i<N;i++) if(le[i]==-1||ri[i]==-1){printf("No\n");return 0;}
	for(int i=0;i<N;i++) if(le[i]>ri[i]){printf("No\n");return 0;}
	printf("Yes\n");
	return 0;
}