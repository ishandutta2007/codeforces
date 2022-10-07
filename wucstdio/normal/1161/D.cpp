#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
char s[1005];
int n,top,in[1005][2],num;
bool res[1005][2],flag[1005],rev[1005];
ll ans;
bool check(int st)
{
	for(int i=1;i<=n;i++)
	{
		if(i<st)
		{
			if((res[i][0]==0&&s[i]=='1')||(res[i][0]==1&&s[i]=='0'))
			  return 0;
		}
		else if(((res[i][0]^res[i][1])==0&&s[i]=='1')||((res[i][0]^res[i][1])==1&&s[i]=='0'))return 0;
		else if(i==st&&res[i][1]==0)return 0;
	}
	return 1;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int st=2;st<=n;st++)
	{
		memset(in,0,sizeof(in));
		memset(flag,1,sizeof(flag));
		memset(rev,0,sizeof(rev));
		num=0;
		for(int i=1;i<=n;i++)
		{
			if(in[i][0]==0)
			{
				in[i][0]=++num;
				int nowx=i,nowy=0;
				res[i][0]=1;
				while(1)
				{
					bool pre=res[nowx][nowy];
					if(nowy)nowx=st+n-nowx;
					else nowx=1+n-nowx;
					if(in[nowx][nowy])break;
					res[nowx][nowy]=pre;
					in[nowx][nowy]=num;
					if(s[nowx]=='?')break;
					nowy^=1;
					if(nowy==1&&nowx<st)break;
					in[nowx][nowy]=num;
					res[nowx][nowy]=res[nowx][nowy^1]^(s[nowx]=='1');
				}
			}
			if(i>=st&&in[i][1]==0)
			{
				if(s[i]=='?')
				{
					in[i][1]=++num;
					res[i][1]=1;
				}
				else
				{
					in[i][1]=num;
					res[i][1]=res[i][0]^(s[i]=='1');
				}
				int nowx=i,nowy=1;
				while(1)
				{
					bool pre=res[nowx][nowy];
					if(nowy)nowx=st+n-nowx;
					else nowx=1+n-nowx;
					if(in[nowx][nowy])break;
					res[nowx][nowy]=pre;
					in[nowx][nowy]=num;
					if(s[nowx]=='?')break;
					nowy^=1;
					if(nowy==1&&nowx<st)break;
					in[nowx][nowy]=num;
					res[nowx][nowy]=res[nowx][nowy^1]^(s[nowx]=='1');
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(i<st)
			{
				if((res[i][0]==0&&s[i]=='1')||(res[i][0]==1&&s[i]=='0'))
				{
					rev[in[i][0]]=1;
				}
				if(s[i]!='?')flag[in[i][0]]=0;
			}
			else 
			{
				if(i==st)
				{
					if(res[i][1]==0)rev[in[i][1]]=1;
					flag[in[i][1]]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(rev[in[i][0]])res[i][0]^=1;
			if(rev[in[i][1]])res[i][1]^=1;
		}
		if(!check(st))continue;
		ll now=1;
		for(int i=1;i<=num;i++)
		  if(flag[i])now=now*2%MOD;
		ans+=now;
	}
	printf("%I64d\n",ans%MOD);
	return 0;
}