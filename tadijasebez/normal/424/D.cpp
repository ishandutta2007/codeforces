#include <bits/stdc++.h>
using namespace std;
const int N=305;
const int inf=1e9+7;
struct SegmentSumOffLine
{
	int sum[N];
	SegmentSumOffLine(){}
	void Set(int i, int f){ sum[i]+=f;}
	int Get(int l, int r){ return sum[r]-sum[l-1];}
	void Build(){ for(int i=1;i<N;i++) sum[i]+=sum[i-1];}
} DT[N],UT[N],LT[N],RT[N];
int h[N][N],f,lo,hi;
int Val(int x, int y)
{
	if(x==y) return f;
	return x>y?lo:hi;
}
int GetCW(int x1, int y1, int x2, int y2)
{
	if(x2-x1<2 || y2-y1<2) return -inf;
	return RT[x1].Get(y1+1,y2)+DT[y2].Get(x1+1,x2)+LT[x2].Get(y1,y2-1)+UT[y1].Get(x1,x2-1);
}
int GetCCW(int x1, int y1, int x2, int y2)
{
	if(x2-x1<2 || y2-y1<2) return -inf;
	return LT[x1].Get(y1,y2-1)+UT[y2].Get(x1,x2-1)+RT[x2].Get(y1+1,y2)+DT[y1].Get(x1+1,x2);
}
int main()
{
	int n,m,i,j,k,l,r,t;
	scanf("%i %i %i",&n,&m,&t);
	scanf("%i %i %i",&f,&hi,&lo);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&h[i][j]);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) DT[j].Set(i,Val(h[i-1][j],h[i][j]));
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)	UT[j].Set(i,Val(h[i+1][j],h[i][j]));
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)	LT[i].Set(j,Val(h[i][j+1],h[i][j]));
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)	RT[i].Set(j,Val(h[i][j-1],h[i][j]));
	for(i=1;i<=m;i++) DT[i].Build(),UT[i].Build();
	for(j=1;j<=n;j++) LT[j].Build(),RT[j].Build();
	int sol=inf,x1=1,x2=3,y1=1,y2=3;
	for(i=1;i<=m;i++) for(j=i+2;j<=m;j++)
	{
		for(k=1;k<=n;k++)
		{
			l=n;r=3;
			//while(l<n && GetCW(k,i,l,j)<t) l++;
			//while(r<n && GetCCW(k,i,r,j)<t) r++;
			int top=n,bot=k,mid;
			while(top>=bot)
			{
				mid=top+bot>>1;
				if(GetCW(k,i,mid,j)>=t) l=mid,top=mid-1;
				else bot=mid+1;
			}
			//for(l=k+2;l<=n;l++)
			//{
			//	int tmp=abs(t-GetCW(k,i,l,j));
            //if(tmp<sol) sol=tmp,x1=k,y1=i,x2=l,y2=j;//,printf("1:D\n");
			//}
			r=l;
			for(l=max(3,r-10);l<=min(n,r+10);l++)
			{
			if(abs(t-GetCW(k,i,l,j))<sol) sol=abs(t-GetCW(k,i,l,j)),x1=k,y1=i,x2=l,y2=j;
			}
            //if(abs(t-GetCW(k,i,l-1,j))<sol) sol=abs(t-GetCW(k,i,l-1,j)),x1=k,y1=i,x2=l-1,y2=j;//,printf("2:D\n");
            //if(abs(t-GetCCW(k,i,r,j))<sol) sol=abs(t-GetCCW(k,i,r,j)),x1=k,y1=i,x2=r,y2=j,printf("3:D\n");
            //if(abs(t-GetCCW(k,i,r-1,j))<sol) sol=abs(t-GetCCW(k,i,r-1,j)),x1=k,y1=i,x2=r-1,y2=j,printf("4:D\n");
		}
	}
	//printf("sol:%i\n",sol);
	//printf("sol:%i\n",sol);
	printf("%i %i %i %i\n",x1,y1,x2,y2);
	//printf("%i\n",GetCW(x1,y1,x2,y2));
	//printf("%i\n",GetCW(4,3,6,7));
	//printf("%i\n",GetCW(1,1,4,4));
	//x1=y1=1;x2=y2=4;
	//printf("%i %i %i %i\n",RT[x1].Get(y1+1,y2),DT[y2].Get(x1+1,x2),LT[x2].Get(y1,y2-1),UT[y1].Get(x1,x2-1));
	return 0;
}