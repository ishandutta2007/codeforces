#include <cstdio>
#include <algorithm>

#define CS	const static
#define Rep(i,j,k)	for(int i = (j) ; i <= (k) ; i ++)

using namespace std ;

CS int MaxN = 100010 << 1 ;

int n,m,w ;

int a[MaxN] , b[MaxN] ;
int maxx = 0 , minn = 1000000001 ;

bool check(int x)
{
	Rep(i,1,n)
		b[i] = a[i] - a[i-1] ;
	int u = 0 , p = 0 ;
	Rep(i,1,n)
	{
		u = u + b[i] ;
		if(u < x)
		{
			p += x - u ;
			b[i + w] -= x - u ;
			u = x ;
		}
		if(p > m)	return false ;
	}
	return p <= m ;
}

int main()
{
	
	scanf("%d %d %d",&n,&m,&w) ;
	Rep(i,1,n)	scanf("%d",&a[i]) , maxx = max(maxx , a[i]) , minn = min(minn , a[i]) ;
	
	int l = minn , r = maxx + m , mid , ans = minn ;
	while(l <= r)
	{
		mid = (l + r) >> 1 ;
		if(check(mid))	l = mid + 1 , ans = mid ;
		else	r = mid - 1 ;
	}
	
	printf("%d", ans) ;
	return 0 ;
}