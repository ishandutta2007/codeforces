#include<cstdio>

using namespace std;

int a[100100],b[100100];

struct segtree{
	int N;
	int dat[262144];
	bool same[262144];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=0;i<=2*N-1;i++)
		{
			dat[i]=-1;
			same[i]=true;
		}
	}
	void setchildren(int k)
	{
		if(k>=N) return;
		if(same[k]==false) return;
		same[k]=false;
		same[k*2]=true;
		same[k*2+1]=true;
		dat[k*2]=dat[k];
		dat[k*2+1]=dat[k];
	}
	void update(int l,int r,int x,int k,int a,int b)
	{
		if(r<=a||b<=l) return;
		if(l<=a&&b<=r)
		{
			same[k]=true;
			dat[k]=x;
			return;
		}
		setchildren(k);
		update(l,r,x,k*2,a,(a+b)/2);
		update(l,r,x,k*2+1,(a+b)/2,b);
	}
	int get(int id,int k,int a,int b)
	{
		if(same[k]) return dat[k];
		int mid=(a+b)/2;
		if(id<mid) return get(id,k*2,a,(a+b)/2);
		else return get(id,k*2+1,(a+b)/2,b);
	}
	void update(int l,int r,int x)
	{
		update(l,r,x,1,0,N);
	}
	int get(int id)
	{
		return get(id,1,0,N);
	}
};

segtree base,start;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<N;i++) scanf("%d",b+i);
	base.init(N);
	start.init(N);
	for(int i=0;i<M;i++)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			x--;y--;
			base.update(y,y+k,x);
			start.update(y,y+k,y);
		}
		else
		{
			int id;
			scanf("%d",&id);
			id--;
			int ba=base.get(id),st=start.get(id);
			int ans;
			if(ba==-1) ans=b[id];
			else ans=a[ba+id-st];
			printf("%d\n",ans);
		}
	}
	return 0;
}