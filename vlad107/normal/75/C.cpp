#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

int a,b,T,ll,rr;
std::vector<int>r;

int find(int x){
	int ll=0,rr=r.size()-1;
	while (ll<rr-1){
		int mid=(ll+rr)>>1;
		if (r[mid]<x)
			ll=mid;
		else rr=mid;
	}
	if (r[rr]<=x)return r[rr];
	else return r[ll];
}

int main(){
	scanf("%d%d%d",&a,&b,&T);
	while (a&&b)
		if (a>b)a%=b;
		else b%=a;
	a+=b;
	for (int i=1;i*i<=a;i++)
		if (a%i==0){
			r.push_back(i);
			if (i*i!=a)r.push_back(a/i);
		}
	std::sort(r.begin(),r.end());
	while (T){
		T--;
		scanf("%d%d",&ll,&rr);
		int x=find(rr);
		if (x>=ll&&x<=rr)
			printf("%d\n",x);
		else puts("-1");
	}
}