#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char ch[1100100];
int cnt[1100100];
int wait[1100100];
int N;

bool all_same()
{
	for(int i=0;i<N;i++) if(ch[i]!=ch[0]) return false;
	return true;
}

int main(){
	scanf("%s",ch);
	N=strlen(ch);
	if(all_same())
	{
		printf("0\n");
		return 0;
	}
	cnt[0]=ch[0]=='M'?1:0;
	for(int i=1;i<N;i++)
	{
		if(ch[i]=='M') cnt[i]=cnt[i-1]+1;
		else cnt[i]=cnt[i-1];
	}
	bool fi=true;
	for(int i=0;i<N;i++)
	{
		if(ch[i]=='M') fi=false;
		if(fi)
		{
			if(ch[i]=='F')
			{
				wait[i]=0;
			}
			if(i<N-1&&ch[i+1]=='M') fi=false;
			continue;
		}
		if(ch[i]=='F') wait[i]=wait[i-1]+1;
		else wait[i]=wait[i-1]-1;
		if(wait[i]<0&&ch[i]=='F') wait[i]=0;
	}
	int ans=0;
	for(int i=0;i<N;i++) if(ch[i]=='F'&&cnt[i]>0) ans=max(ans,cnt[i]+wait[i]);
	printf("%d\n",ans);
	return 0;
}