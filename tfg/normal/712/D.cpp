#include <cstdio>

inline int lower(int a, int b){return a<b?a:b;}
inline int greater(int a, int b){return a>b?a:b;}

const long long int MOD=1000000007;

int a,b,k,t;
int lb,hb;
int lowest;
int i=0;
long long int pd[2][1000000];
long long int ps[1000000];

inline int index(int x){return (x<0?x:-x)-lowest;}
inline int index2(int x){return x<hb-2*k?(x-lowest>=0?x-lowest:0):hb-2*k-lowest;}
inline int index3(int x){return x-lowest;}

int main()
{
	scanf("%i %i %i %i",&a,&b,&k,&t);
	
	lowest=-2*(k*t);
	for(int j=lowest;j<-lowest;j++)
	{
		pd[0][index3(j)]=pd[1][index3(j)]=ps[index3(j)]=0;
	}
	//printf("lowest is %i\n\n",lowest);
	if(a-b<lowest)
	{
		printf("0");
		return 0;
	}
	//i=0;
	lb=0;
	hb=0;
	pd[0][index(0)]=1;
	i++;
	while(i<=t)
	{

		int next=i%2, prev=(i+1)%2;
		long long int sum=0;
		lb-=2*k;
		hb+=2*k;
		for(int j=lb+2*k;j<=hb-2*k;j++)
		{
			//printf("sum %i = %lli+%lli, index %i\n",j,sum,pd[prev][index(j)],index(j));
			sum=(sum+pd[prev][index(j)])%MOD;
			ps[index2(j)]=sum;
		}
		sum=0;
		int j=0,indj=lb;
		//j=0
		pd[next][index(lb)]=1;
		j++;
		indj++;
		while(j<=k+1)
		{
			//printf("pd[%i]=%lli + %lli\n",j,pd[next][index(indj-1)],
			//	ps[index2(indj+2*k)]);
			pd[next][index(indj)]=(
				pd[next][index(indj-1)]+
				ps[index2(indj+2*k)]
				)%MOD;
			j++;
			indj++;
		}
		while(j<=hb)
		{
			//printf("pd[%i]=%lli-(%lli-%lli)+(%lli-%lli)\n",j,pd[next][index(indj-1)],ps[index2(indj-1)],
			//	ps[index2(indj-2*k-2)],ps[index2(indj+2*k)],ps[index2(indj-1)]);
			pd[next][index(indj)]=(
				pd[next][index(indj-1)]-
				(ps[index2(indj-1)]-ps[index2(indj-2*k-2)])%MOD
				+(ps[index2(indj+2*k)]-ps[index2(indj-1)])%MOD
				+MOD)%MOD;
			j++;
			indj++;
		}
		i++;
		/*printf("Iteration %i:\n",i);
		for(int ab=lb;ab<=hb;ab++) printf("%lli ",pd[next][index(ab)]);
		printf("\nSum:\n");
		for(int ab=lb;ab<=hb;ab++) printf("%i ",ps[index2(ab)]);
		printf("\n\n");*/
	}
	long long int ans=0;
	for(int j=a-b-1;j>=lowest;j--)
	{
		//printf("ans += %lli\n",pd[(i+1)%2][index(j)]);
		ans=(ans+pd[(i+1)%2][index(j)])%MOD;
	}
	printf("%lli",ans);
}