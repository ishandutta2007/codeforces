#include<iostream>
#include<algorithm>
#include<cmath>
#include <cstring>
#include <cstdio>
#include <limits>
using namespace std;

int n,x,y;
int a[100009];
int q[100009],lq,rq;
int p[100009],lp,rp;
bool befo[100009],aft[100009];
int main()
{
	memset(befo,0,sizeof(befo));
	memset(aft,0,sizeof(aft));
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	lq=1,rq=0;
	for(int i=1;i<=n;i++){
		q[++rq]=i;
		while(q[lq]<i-x) lq++;
		int flag=1;
		for(int j=lq;j<rq;j++)
			if(a[q[j]]<=a[i]){
				flag=0;
				break;
			}
		befo[i]=flag;	
	}
	lp=1,rp=0;
	for(int i=n;i>=1;i--){
		p[++rp]=i;
		while(p[lp]>i+y) lp++;
		int flag=1;
		for(int j=lp;j<rp;j++)
			if(a[p[j]]<=a[i]){
				flag=0;
				break;
			}
		aft[i]=flag;
	}
	for(int i=1;i<=n;i++){
		if(befo[i]&&aft[i]){
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}