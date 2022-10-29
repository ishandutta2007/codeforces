#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

int a[1010] , b[1010] ;

int n,k,d ;

int main()
{
	scanf("%d %d %d",&n,&k,&d) ;

	double p = n ; k = min (n , k) ;
	for (int i = 1 ; i <= d ; i ++)
		p /= k ;

	if(p > 1.0)
	{
		puts("-1") ;
		return 0 ;
	}

	p = n ; a[a[0]=1] = n ;
	for (int i = 1 ; i <= d ; i ++)
	{
		if(p <= 1.0)
		{
			for (int j = 1 ; j <= n ; j ++)
				printf("1 ");
			puts("") ;
			continue ;
		}
		else
		{
			p /= k ; b[0] = 0 ;
			for (int j = 1 ; j <= a[0] ; j ++)
			{
				int u = (a[j] + k - 1) / k , cnt = a[j] ;
				if(u==0)	continue ;
				for (int l = 1 ; l <= k ; l ++)
				{
					if(!cnt)	break ;
					if(cnt >= u)
					{
						cnt -= u ;
						b[++b[0]] = u ;
					}
					else
						if(cnt)
						{
							b[++b[0]] = cnt ;
							cnt = 0 ;
						}
					for (int o = 1 ; o <= b[b[0]] ; o ++)
						printf("%d ",l);
				}
			}
			for (int j = 0 ; j <= b[0] ; j ++)
				a[j] = b[j] ;
			puts("") ;
		}
	}

	return 0;
}