#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
	int x[2],where;
	void scan(){
		scanf("%d%d",&x[0],&x[1]);
	}
}A[1100000];
int d;
int operator < (point k1,point k2){
	return k1.x[d]<k2.x[d];
}
int n,p[1100000],len;
void getans(int L,int R,int pd){
	d=pd; int mid=L+R>>1;
	nth_element(A+L,A+mid,A+R+1);
	p[++len]=A[mid].where;
	if (mid>L) getans(L,mid-1,pd^1);
	if (mid<R) getans(mid+1,R,pd^1);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) A[i].scan(),A[i].where=i;
	getans(1,n,0);
	for (int i=1;i<=n;i++) printf("%d ",p[i]); printf("\n");
	return 0;
}