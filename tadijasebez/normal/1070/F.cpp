#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=400050;
int cnt[4];
ll sum[4][N];
int main()
{
	int n,i,j,x,y;char t[4];
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
        scanf("%s %i",t,&x);
        y=0;
        if(t[0]=='1') y+=2;
        if(t[1]=='1') y+=1;
        cnt[y]++;
        sum[y][cnt[y]]=x;
	}
	for(i=0;i<4;i++) sort(sum[i]+1,sum[i]+1+cnt[i]),reverse(sum[i]+1,sum[i]+1+cnt[i]);
	for(i=0;i<4;i++) for(j=1;j<=cnt[i];j++) sum[i][j]+=sum[i][j-1];
	ll ans=0;
    for(i=min(cnt[0],cnt[3]);i>=0;i--)
	{
		int h=cnt[3]-i;ll tmp;
        //printf("h:%i ",h);
        x=min(cnt[1],cnt[2]+h);
        y=min(x,max(cnt[2],x-h));
        if(x>=0 && y>=0)
		{
			tmp=sum[3][cnt[3]]+sum[0][i]+sum[1][x]+sum[2][y];
			//printf("x:%i y:%i tmp:%lld ",x,y,tmp);
			ans=max(ans,tmp);
		}
        y=min(cnt[1]+h,cnt[2]);
        x=min(y,max(y-h,cnt[1]));
        if(x>=0 && y>=0)
		{
			tmp=sum[3][cnt[3]]+sum[0][i]+sum[1][x]+sum[2][y];
			ans=max(ans,tmp);
			//printf("x:%i y:%i tmp:%lld\n",x,y,tmp);
		}
	}
	printf("%lld\n",ans);
	return 0;
}