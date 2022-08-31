#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct point{
	int a,b,c;
	void scan(){
		scanf("%d%d%d",&a,&b,&c);
	}
}x[510000];
int compare(point k1,point k2){
	return k1.c<k2.c;
};
const int N=510000;
int n;
int A[N],B[N],limA,limB,limC;
long long preA[N],preB[N],tot;
int main(){
	scanf("%d%d%d%d",&n,&limA,&limB,&limC);
	for (int i=1;i<=n;i++) x[i].scan();
	for (int i=1;i<=n;i++) A[x[i].a]=max(A[x[i].a],x[i].b);
	for (int i=limA;i;i--) A[i]=max(A[i],A[i+1]);
	for (int i=1;i<=n;i++) B[x[i].b]=max(B[x[i].b],x[i].a);
	for (int i=limB;i;i--) B[i]=max(B[i],B[i+1]);
	tot=0;
	for (int i=1;i<=limA;i++) tot+=limB-A[i];
	for (int i=1;i<=limA;i++) preA[i]=preA[i-1]+limB-A[i];
	for (int i=1;i<=limB;i++) preB[i]=preB[i-1]+limA-B[i];
	sort(x+1,x+n+1,compare); int now=n,wA=0,wB=0;
	long long ans=0;
	//cout<<tot<<endl;
	//for (int i=1;i<=limA;i++) cout<<A[i]<<" "; cout<<endl;
	//for (int i=1;i<=limB;i++) cout<<B[i]<<" "; cout<<endl;
	for (int i=limC;i;i--){
		while (now&&x[now].c==i){
			wA=max(wA,x[now].a+1); wB=max(wB,x[now].b+1); now--;
		}
	//	cout<<"fa "<<wA<<" "<<wB<<endl;
		if (A[wA]<wB) ans+=1ll*(limA-wA+1)*(limB-wB+1);
		else {
			ans+=tot-preA[wA-1]-preB[wB-1];
		}
	}
	cout<<ans<<endl;
	return 0;
}