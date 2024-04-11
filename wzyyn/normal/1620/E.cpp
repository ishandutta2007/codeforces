#include<bits/stdc++.h>

using namespace std;

const int N=500005;
int Q;
int tp[N],qx[N],qy[N],re[N],a[N];
int main(){
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		scanf("%d%d",&tp[i],&qx[i]);
		if (tp[i]==2) scanf("%d",&qy[i]);
	}
	for (int i=1;i<N;i++) re[i]=i;
	for (int i=Q;i>=1;i--)
		if (tp[i]==1) a[++*a]=re[qx[i]];
		else re[qx[i]]=re[qy[i]];
	for (;*a;--*a) printf("%d ",a[*a]);
}