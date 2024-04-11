#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>

int n,inf;
double a[20][20],f[2000000];
std::vector<int> w;

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			scanf("%lf",&a[i][j]);
	inf=1<<n;
	for (int i=0;i<inf;i++)f[i]=0.0;
	f[inf-1]=1.0;
	for (int mask=inf-1;mask>=0;mask--){
		int x=mask;
		w.clear();
		for (int j=n-1;j>=0;j--){
			if (x%2==0){
				x/=2;
				continue;
			}
			w.push_back(j);
			x/=2;
		}
		double p=1;
		p/=w.size();
		p/=(w.size()-1);
		p*=2;
		for (int i=0;i<w.size();i++)
			for (int j=i+1;j<w.size();j++){
				f[mask-(1<<(n-w[j]-1))]+=f[mask]*a[w[i]][w[j]]*p;
				f[mask-(1<<(n-w[i]-1))]+=f[mask]*a[w[j]][w[i]]*p;
			}
	}
	for (int i=inf/2;i>0;i/=2)printf("%.9lf ",f[i]);
}