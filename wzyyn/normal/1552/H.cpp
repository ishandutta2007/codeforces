#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

int Query(int v){
	printf("? %d\n",200*(200>>v));
	for (int i=1;i<=200;i++)
		for (int j=1<<v;j<=200;j+=1<<v)
			printf("%d %d ",i,j);
	puts("");
	fflush(stdout);
	scanf("%d",&v);
	return v;
}
int main(){
	int v1=Query(0);
	int l=1,r=7,p=8,vb=0;
	while (l<=r){
		int mid=(l+r)/2;
		int v=Query(mid);
		if (v*(1<<mid)==v1)
			l=mid+1;
		else{
			p=mid;
			r=mid-1;
			vb=v;
		}
	}
	int w=abs(vb*(1<<p)-v1)>>(p-1);
	printf("! %d\n",2*(w+v1/w-2));
}