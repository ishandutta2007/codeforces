

#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long
map<int,int> cnt,cnn;
const int N=100050;
int a[N];
int main()
{
	int n,x,k,i,b,j;
	ll sol=0;
	scanf("%i %i %i",&n,&x,&k);
        for(i=1;i<=n;i++) scanf("%i",&a[i]);
        sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
                j=i;
                while(j<=n && a[j]==a[i])
                {
		    if(a[i]%x!=0) b=a[i]+(x-(a[i]%x));
		    else b=a[i];
		    b/=x;
		    cnt[b]++;
                    j++;
                }
                j=i;
                while(j<=n && a[j]==a[i])
                {
		    //printf("%i ",b);
		    b=a[i]+(x-(a[i]%x));
		    b/=x;
		    sol+=cnt[b-k];
		    //printf("%i %i %i\n",b,c,sol);
                    j++;
                }
                i=j-1;
	}
	printf("%lld\n",sol);
	return 0;
}