#include <bits/stdc++.h>
using namespace std;
const int N=305;
int ans[N],tmp[N];
int tr;
void work(int l, int r)
{
	printf("? %i %i\n",l,r);
	fflush(stdout);
	scanf("%i",&tr);
}
int main()
{
	int n,i,j,o;
	scanf("%i %i",&n,&o);
	tr=o;int ost=o;
	for(i=1;i<n;i++)
	{
		int p;
		for(j=1;j<=20;j++)
		{
			p=tr;
            work(i+1,n);
            work(i+1,n);
            if(p!=tr) break;
		}
		if(p!=tr)
		{
			int f=0;
			for(j=1;j<i;j++) tmp[j]^=1,f+=tmp[j];
			if(f+ost-1==tr) tmp[i]=0,ans[i]=1;
			else tmp[i]=1,ans[i]=0;
			ost-=ans[i];
		}
		else
		{
			int cnt[2]={0,0};
			for(j=1;j<i;j++) cnt[tmp[j]]++;
			if(cnt[0]<cnt[1]) tmp[i]=0,ans[i]=0;
			else tmp[i]=1,ans[i]=1;
			ost-=ans[i];
		}
	}
	if(ost) ans[i]=1;
	printf("! ");
	for(int i=1;i<=n;i++) printf("%i",ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}