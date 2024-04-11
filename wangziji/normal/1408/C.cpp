#include <iostream>
#include <cstdio>
using namespace std;
double a[100005],qzh[100005],hzh[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		double l;
		cin >> n >> l;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			qzh[i]=qzh[i-1]+(a[i]-a[i-1])/(double)i;
		a[n+1]=l,hzh[n+1]=0;
		for(int i=n;i>=1;i--)
			hzh[i]=hzh[i+1]+(a[i+1]-a[i])/(double)(n-i+1);
		for(int i=0;i<=n;i++)
		{
			//t1=qzh[i],t2=hzh[i+1]
			if(qzh[i]<=hzh[i]+1e-7&&qzh[i+1]>hzh[i+1]-1e-7)
			{
//				cout << i << " " << qzh[i] << " " << hzh[i+1] << " " << a[i+1]-a[i] << "**********************\n";
				if(hzh[i+1]>qzh[i])
					printf("%.10lf\n",max(hzh[i+1],qzh[i])+(a[i+1]-a[i]-(max(hzh[i+1],qzh[i])-min(hzh[i+1],qzh[i]))*(i+1))/(double)(n+2));
				else 
					printf("%.10lf\n",max(hzh[i+1],qzh[i])+(a[i+1]-a[i]-(max(hzh[i+1],qzh[i])-min(hzh[i+1],qzh[i]))*(n-i+1))/(double)(n+2));
				break;
			}
		}
	}
	return 0;
}