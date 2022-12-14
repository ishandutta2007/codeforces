#include<cstdio>
#include<cstring>

using namespace std;

const int days[]={31,28,31,30,31,30,31,31,30,31,30,31};

char ch[100100];

int cnt[3][13][32];

int get(char ch)
{
	return ch-'0';
}

int main()
{
	scanf("%s",ch);
	int ln=strlen(ch);
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i+9<ln;i++)
	{
		bool ok=true;
		for(int j=0;j<9;j++)
		{
			if(j==2||j==5)
			{
				if(ch[i+j]!='-') ok=false;
			}
			else
			{
				if(ch[i+j]=='-') ok=false;
			}
		}
		if(ok==false) continue;
		int dd=0,mm=0,yy=0;
		dd=get(ch[i+0])*10+get(ch[i+1]);
		mm=get(ch[i+3])*10+get(ch[i+4]);
		yy=get(ch[i+6])*1000+get(ch[i+7])*100+get(ch[i+8])*10+get(ch[i+9]);
		if(yy<=2012||yy>=2016) continue;
		if(mm<=0||mm>12) continue;
		if(dd>days[mm-1]||dd==0) continue;
		cnt[yy-2013][mm][dd]++;
	}
	int ans_y,ans_m,ans_d;
	int ans=0;
	for(int i=0;i<3;i++) for(int j=1;j<=12;j++) for(int k=1;k<=31;k++)
	{
		if(cnt[i][j][k]>ans)
		{
			ans=cnt[i][j][k];
			ans_y=i;ans_m=j;ans_d=k;
		}
	}
	printf("%02d-%02d-%d\n",ans_d,ans_m,ans_y+2013);
	return 0;
}