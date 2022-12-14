#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

char ch[200200];
int pts[200200];

const int inf=1100100;

struct RMQ{
	int N;
	int dat[525000];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=0;i<=N*2-1;i++) dat[i]=-inf;
	}
	void getarray(int *a,int len)
	{
		for(int i=0;i<len;i++) dat[i+N]=a[i];
		for(int i=N-1;i>=1;i--)
		{
			dat[i]=max(dat[i*2],dat[i*2+1]);
		}
	}
	int query(int x)
	{
		//maximum id whose val is >=x
		int k=1;
		int l=0,r=N;
		while(r-l>1)
		{
			if(dat[k*2+1]>=x)
			{
				l=(l+r)/2;
				k=k*2+1;
			}
			else
			{
				r=(l+r)/2;
				k*=2;
			}
		}
		return k-N;
	}
};

RMQ rmq;

string vows="aiueoAIUEO";

bool isvow(char ch)
{
	for(int i=0;i<10;i++) if(ch==vows[i]) return true;
	return false;
}

int main()
{
	scanf("%s",ch);
	int N=strlen(ch);
	rmq.init(N+1);
	pts[0]=0;
	for(int i=1;i<=N;i++)
	{
		if(isvow(ch[i-1])) pts[i]=pts[i-1]-1;
		else pts[i]=pts[i-1]+2;
	}
	rmq.getarray(pts,N+1);
	int len=-1,cnt=0;
	for(int i=0;i<N;i++)
	{
		int r=rmq.query(pts[i]);
		if(i==r) continue;
		if(len>r-i) continue;
		if(len==r-i) cnt++;
		else
		{
			len=r-i;
			cnt=1;
		}
	}
	if(len==-1)
	{
		printf("No solution\n");
	}
	else
	{
		printf("%d %d\n",len,cnt);
	}
	return 0;
}