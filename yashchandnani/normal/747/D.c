#include <stdio.h>
int main()
{
	long int n,k;
	scanf("%ld %ld",&n,&k);
	int a[n];
	long int count[n+1];
	for (int i = 0; i <=n; ++i)
	{
		count[i]=0;
	}
	long int t = 0,t1 =-1 ,t2 =0;
	a[0]=2;
	long int i = 1;
	for (; a[i-1] >=0; ++i)
	{	scanf("%d",&a[i]);
		t1++;
		if ((i == n )&&(a[i]>=0))
		{ 
			printf("0" );
			return 0;
		}
		
	}
	long int max  = 0;
	long int nv = 1;
	for (; i <=n; ++i)
	{	scanf("%d",&a[i]);
		if (a[i]>=0)
		{
			t++;
		}
		else{
			if (t>max)
			{
				max  = t ;
			}
			count[t]++;
			t =0 ;
			nv++;
		}
	}

	if (nv>k)
	{
		printf("-1");
		return 0;
	}

	for (long int i = n; a[i]>=0; i--)
	{	t2++;
		
	}
	
	long int rem = k - nv ;
	
	long int start = 1;
	while((rem>0)&&(start<=max)){
		if(rem>=(start*count[start])){
			rem = rem -start*count[start];
			count[start]=0;	
			start++;	
		}
		else if(rem>start){
			count[start] -= rem/start ; 
			rem = rem - (rem/start)*start ;

		}
		else break ;
		
	}
	//printf("%ld\n",rem );
	if(rem>=t2){
			t2  = 0;
		}
	if (count[max]==0)
	{	if (t2!=0)
		{
		printf("2");
		}
		else{
		printf("1");}
		return 0;
	}
	else{
		long int ans = 0;

		while(start<=max){
			
			ans= ans + count[start];
			
			start++;
		}
		ans = 2*ans + 1;
		
		if (t2!=0){
			ans++;
		}
		printf("%ld\n",ans );
	}
	return 0;
}