#include<cstdio>
#include<algorithm>

using namespace std;

//bool field[1010][1010];

bool ok_i[1010],ok_j[1010];

bool tmp[10];

int ban[8][2]={{0,5},{1,4},{2,7},{3,6},{1,2},{3,4},{5,6},{0,7}};

bool check(int mask,int i)
{
	if(((mask>>i)&1)==1) return true;
	return false;
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<1010;i++)
	{
		ok_i[i]=true;
		ok_j[i]=true;
	}
	for(int i=0;i<M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		ok_i[x]=false;ok_j[y]=false;
	}
	int ans=0;
	for(int i=1;i<=(N/2)-1;i++)
	{
		int s=i,t=N-1-i;
		for(int j=0;j<10;j++) tmp[j]=true;
		if(ok_i[s]==false) tmp[0]=false,tmp[5]=false;
		if(ok_i[t]==false) tmp[1]=false,tmp[4]=false;
		if(ok_j[s]==false) tmp[2]=false,tmp[7]=false;
		if(ok_j[t]==false) tmp[3]=false,tmp[6]=false;
		int ma=0;
		for(int mask=0;mask<(1<<8);mask++)
		{
			bool ok=true;
			for(int j=0;j<8;j++)
			{
				if(((mask>>j)&1)==1&&tmp[j]==false) ok=false;
			}
			if(ok==false) continue;
			for(int j=0;j<8;j++)
			{
				int a=ban[j][0],b=ban[j][1];
				if(check(mask,a)&&check(mask,b)) ok=false;
			}
			if(ok==false) continue;
			int c=0;
			for(int j=0;j<8;j++)
			{
				if(check(mask,j)) c++;
			}
			ma=max(ma,c);
		}
		ans+=ma;
	}
	if(N%2==1)
	{
		if(ok_i[N/2]==true||ok_j[N/2]==true) ans++;
	}
	printf("%d\n",ans);
	return 0;
}