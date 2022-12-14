#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

long long exps[100100][6];//[i][j]=i^j
long long exp_sum[100100][6];

struct range_sum{
	int type;
	int N;
	long long dat[262144];
	long long val[262144];
	bool same[262144];
	void init(int N_,int id)
	{
		type=id;
		N=1;
		while(N<N_) N*=2;
		for(int i=0;i<=N*2-1;i++) dat[i]=0;
		for(int i=0;i<=N*2-1;i++) val[i]=0;
		for(int i=0;i<=N*2-1;i++) same[i]=true;
	}
	void update(int l,int r,int x,int k,int a,int b)
	{
		if(r<=a||b<=l) return;
		if(l<=a&&b<=r)
		{
			val[k]=x;
			long long tmp=(long long)x*(exp_sum[b-1][type]-exp_sum[a-1][type]);
			tmp%=mod;
			dat[k]=tmp;
			same[k]=true;
			return;
		}
		if(same[k]==true)
		{
			//update(l,r,val[k],k*2,a,(a+b)/2);
			//update(l,r,val[k],k*2+1,(a+b)/2,b);
			for(int id=k*2;id<=k*2+1;id++)
			{
				same[id]=true;
				val[id]=val[k];
				int aa=id==k*2?a:(a+b)/2;
				int bb=id==k*2?(a+b)/2:b;
				long long tmp=exp_sum[bb-1][type];
				if(aa!=0) tmp-=exp_sum[aa-1][type];
				dat[id]=tmp*val[id];
				dat[id]%=mod;
			}
		}
		same[k]=false;
		update(l,r,x,k*2,a,(a+b)/2);
		update(l,r,x,k*2+1,(a+b)/2,b);
		dat[k]=dat[k*2]+dat[k*2+1];
	}
	void update(int l,int r,int x)
	{
	//	if(type==1) printf("aa%d %d %d\n",l,r,x);
		update(l,r,x,1,0,N);
	}
	long long query(int l,int r,int k,int a,int b)
	{
		if(r<=a||b<=l) return 0;
		if(l<=a&&b<=r)
		{
			return dat[k];
		}
		if(same[k])
		{
			//long long res=exp_sum[b-1][type]-exp_sum[a-1][type];
			//res*=val[k];
			//res%=mod;
			//return res;
			for(int id=k*2;id<=k*2+1;id++)
			{
				same[id]=true;
				val[id]=val[k];
				int aa=id==k*2?a:(a+b)/2;
				int bb=id==k*2?(a+b)/2:b;
				long long tmp=exp_sum[bb-1][type];
				if(aa!=0) tmp-=exp_sum[aa-1][type];
				dat[id]=tmp*val[id];
				dat[id]%=mod;
			}
			//return res;
		}
		long long tmp=query(l,r,k*2,a,(a+b)/2)+query(l,r,k*2+1,(a+b)/2,b);
		tmp%=mod;
		return tmp;
	}
	long long query(int l,int r)
	{
		return query(l,r,1,0,N);
	}
};

range_sum seg[6];

int a[100100];

long long C[6][6];

long long solve(int l,int r,int k)
{
	if(k==0)
	{
		return seg[0].query(l,r);
	}
	long long a=l-1;
	long long res=0;
	for(int e=k;e>=0;e--)
	{
		long long coe=1;
		for(int i=0;i<k-e;i++)
		{
			coe*=a;
			coe%=mod;
		}
		coe*=C[k][e];
		coe%=mod;
		long long val=coe;
		val*=seg[e].query(l,r);
		val%=mod;
		if((e-k)%2==0) res+=val;
		else res-=val;
	}
	res%=mod;
	return res;
}

void update(int l,int r,int x)
{
	for(int i=0;i<=5;i++) seg[i].update(l,r,x);
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i+1);
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=5;j++)
		{
			long long tmp=1;
			for(int k=0;k<j;k++)
			{
				tmp*=i;
				tmp%=mod;
			}
			exps[i][j]=tmp;
		}
	}
	for(int i=0;i<=5;i++)
	{
		exp_sum[0][i]=0;
		for(int j=1;j<=N;j++)
		{
			exp_sum[j][i]=exp_sum[j-1][i]+exps[j][i];
			exp_sum[j][i]%=mod;
		}
	}
	for(int i=0;i<=5;i++) seg[i].init(N+1,i);
	for(int i=0;i<=5;i++)
	{
		for(int j=1;j<=N;j++)
		{
			seg[i].update(j,j+1,a[j]);
		}
	}
	for(int i=1;i<=5;i++)
	{
		for(int j=0;j<=i;j++)
		{
			long long tmp=1;
			for(int k=1;k<=j;k++) tmp*=(i-k+1);
			for(int k=1;k<=j;k++) tmp/=k;
			C[i][j]=tmp;
		}
	}
	for(int q=0;q<M;q++)
	{
	//	printf("query %d\n",q);
		char ch[2];
		scanf("%s",ch);
		if(ch[0]=='=')
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			r++;
			update(l,r,x);
		}
		else
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			r++;
			long long ans=solve(l,r,k);
			ans%=mod;
			ans+=mod;
			ans%=mod;
			printf("%d\n",(int)ans);
		}
	}
	return 0;
}