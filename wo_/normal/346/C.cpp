#include<cstdio>
#include<algorithm>

using namespace std;

struct RmQ{
	int N;
	int dat[2097152];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=0;i<=N*2-1;i++) dat[i]=(1<<29);
	}
	void update(int id,int x)
	{
		id+=N;
		while(id>0)
		{
			dat[id]=min(dat[id],x);
			id/=2;
		}
	}
	int get(int l,int r,int k,int a,int b)
	{
		if(l<=a&&b<=r) return dat[k];
		if(r<=a||b<=l) return (1<<29);
		return min(get(l,r,k*2,a,(a+b)/2),get(l,r,k*2+1,(a+b)/2,b));
	}
	int get(int l,int r)
	{
		return get(l,r,1,0,N);
	}
};

RmQ rmq;

int ri[1100100];
int A,B;
int x[100100];

int dp[1100100];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",x+i);
	scanf("%d%d",&A,&B);
	sort(x,x+N);
	N=unique(x,x+N)-x;
	for(int i=0;i<=A-B;i++) ri[i]=i+1;
	for(int i=0;i<N;i++){
		int st=(B/x[i])*x[i];
		if(st<B) st+=x[i];
		for(;st<A;st+=x[i]){
			ri[st-B]=max(st+x[i]-1-B,ri[st-B]);
			ri[st-B]=min(ri[st-B],A-B);
		}
	}
	dp[A-B]=0;
	rmq.init(A-B+1);
	rmq.update(A-B,0);
	for(int i=A-B-1;i>=0;i--)
	{
		int tmp=rmq.get(i,ri[i]+1);
		dp[i]=tmp+1;
		rmq.update(i,dp[i]);
	}
	printf("%d\n",dp[0]);
	return 0;
}