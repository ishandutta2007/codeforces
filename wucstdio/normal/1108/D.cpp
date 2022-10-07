#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const char res[4]={"RGB"};
int n,f[200005][4],ans[200005];
char s[200005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	memset(f,0x3f,sizeof(f));
	f[0][0]=f[0][1]=f[0][2]=0;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=min(f[i-1][1],f[i-1][2])+1;
		f[i][1]=min(f[i-1][0],f[i-1][2])+1;
		f[i][2]=min(f[i-1][0],f[i-1][1])+1;
		if(s[i]=='R')f[i][0]--;
		if(s[i]=='G')f[i][1]--;
		if(s[i]=='B')f[i][2]--;
	}
	int now1=n,now2=0;
	if(f[n][1]<f[n][now2])now2=1;
	if(f[n][2]<f[n][now2])now2=2;
	printf("%d\n",f[n][now2]);
	while(now1)
	{
		ans[now1]=now2;
		now1--;
		if(now2==0)now2=(f[now1][1]>f[now1][2]?2:1);
		else if(now2==1)now2=(f[now1][0]>f[now1][2]?2:0);
		else if(now2==2)now2=(f[now1][0]>f[now1][1]?1:0);
	}
	for(int i=1;i<=n;i++)
	  putchar(res[ans[i]]);
	putchar('\n');
	return 0;
}