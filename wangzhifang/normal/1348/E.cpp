#include <bitset>
#include <cstdio>
using namespace std;
bitset<501>t,r;
int main(){
	int n,k;
	long long s=0;
	scanf("%d%d",&n,&k);
	t[0]=1;
	int c=0,d=0;
	for(int i=0,a,b; i<n; ++i){
		scanf("%d%d",&a,&b);
		s+=(c+a)/k+(d+b)/k;
		c=(c+a)%k,d=(d+b)%k;
		r=0;
		for(int j=0; j<k; ++j)
			if(t[j])
				for(int l=1; l<min(b+1,k); ++l)
					if(k-l<=a)
						r[(j+l)%k]=1;
		t|=r;
	}
	for(int i=0; i<=c+d-k; ++i)
		if(t[(i-c+k)%k])
			++s,i=k;
	printf("%lld\n",s);
	return 0;
}