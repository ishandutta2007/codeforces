#include<bits/stdc++.h>
using namespace std;
int n,m;
#define N 210001
#define PER(i,a,b) for(int i=a;i<=b;i++)
int a[N],b[N];int p[N];int c[N];bool pg[4][4];int t[4][4][2*N];int size[4][4];
void up(int x,int y,int k)
{
	while(k>1&&t[x][y][k]<t[x][y][k/2]) 
	{
		swap(t[x][y][k],t[x][y][k/2]);
		k/=2;
	}
}
void down(int x,int y,int k)
{
	int j;
	int le=k*2,ri=le+1;
	while(le<=size[x][y])
	{
		if(le==size[x][y]||t[x][y][le]<t[x][y][ri]) j=le;else j=ri;
		if(t[x][y][j]<t[x][y][k]) swap(t[x][y][j],t[x][y][k]);
		else return;
		k=j;le=k*2,ri=le+1;
	}
	return;
}
void add(int x,int y,int p)
{
	int num=++size[x][y];
	t[x][y][num]=p;up(x,y,num);
}
int co;
int back,on[4];
int QwQ;
int bb,cc;
int main()
{
	scanf("%d",&n); PER(i,1,n) scanf("%d",&p[i]);
	PER(i,1,3)PER(j,1,3)PER(xx,1,n+1) t[i][j][xx]=2e9;
	PER(i,1,n)scanf("%d",&a[i]);PER(i,1,n)scanf("%d",&b[i]);
	PER(i,1,n) if(a[i]>b[i]) swap(a[i],b[i]);
	PER(i,1,n) add(a[i],b[i],p[i]);	scanf("%d",&m);
	PER(i,1,m)
	{
		scanf("%d",&co);
		PER(j,1,3)
		{
			bb=co;cc=j;
			if(bb>cc) swap(bb,cc);
			on[j]=t[bb][cc][1];
		}
		QwQ=2e9;
		PER(j,1,3) {if(QwQ>on[j]) {back=j;QwQ=on[j];}}if(back==0||QwQ>1e9+4001) QwQ=-1;
		printf("%d ",QwQ);
		bb=co;cc=back;if(bb>cc) swap(bb,cc);t[bb][cc][1]=2e9+5;down(bb,cc,1); 	
	}
}