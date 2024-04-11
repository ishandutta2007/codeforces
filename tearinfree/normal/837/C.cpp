#include <cstdio>
#include <algorithm>

int n,xx[100],yy[100],a,b;

int main() {
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<n;i++) scanf("%d%d",xx+i,yy+i);
	
	int mx=0;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
		int w=std::max(xx[i],xx[j]),h=yy[i]+yy[j];
		if((w<=a&&h<=b)||(w<=b&&h<=a)) {
			int sum=xx[i]*yy[i]+xx[j]*yy[j];
			if(mx<sum) mx=sum;
		}

		w=std::max(xx[i],yy[j]),h=yy[i]+xx[j];
		if((w<=a&&h<=b)||(w<=b&&h<=a)) {
			int sum=xx[i]*yy[i]+xx[j]*yy[j];
			if(mx<sum) mx=sum;
		}

		w=std::max(yy[i],xx[j]),h=xx[i]+yy[j];
		if((w<=a&&h<=b)||(w<=b&&h<=a)) {
			int sum=xx[i]*yy[i]+xx[j]*yy[j];
			if(mx<sum) mx=sum;
		}

		w=std::max(yy[i],yy[j]),h=xx[i]+xx[j];
		if((w<=a&&h<=b)||(w<=b&&h<=a)) {
			int sum=xx[i]*yy[i]+xx[j]*yy[j];
			if(mx<sum) mx=sum;
		}
	}
	printf("%d\n",mx);
	return 0;
}