#include<bits/stdc++.h>
using namespace std;
#define ll long long
int Big,n,m,x,y,A[300001],B[1005][1005];
ll Ans;
void update(int k) {
	int l=max(1,k*Big),r=min(n,(k+1)*Big-1);
	B[k][0]=0;
	for(int i=l; i<=r; i++)B[k][++B[k][0]]=A[i];
	sort(B[k]+1,B[k]+B[k][0]+1);
}
ll Num(int l,int r,int x,int y) {
	ll res=0;
	int L=l/Big,R=r/Big;
	if(L==R) {
		for(int i=l; i<=r; i++)if(x<A[i]&&A[i]<y)res++;
	} else {
		for(int i=l; i<(L+1)*Big; i++)if(x<A[i]&&A[i]<y)res++;
		for(int i=L+1; i<R; i++) {
			int a=lower_bound(B[i]+1,B[i]+B[i][0]+1,y)-B[i],b=lower_bound(B[i]+1,B[i]+B[i][0]+1,x)-B[i];
			res+=a-b;
		}
		for(int i=R*Big; i<=r; i++)if(x<A[i]&&A[i]<y)res++;
	}
	return res*2;
}
int main() {
	scanf("%d%d",&n,&m);
	Big=(int)sqrt(n*1.0);
	for(int i=1; i<=n; i++)A[i]=i,B[i/Big][++B[i/Big][0]]=i;
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		if(x!=y) {
			if(x>y)swap(x,y);
			int L=x/Big,R=y/Big;
			swap(A[x],A[y]);
			update(L),update(R);
			if(A[x]<A[y])Ans-=Num(x,y,A[x],A[y])+1;
			else Ans+=Num(x,y,A[y],A[x])+1;
		}
		printf("%lld\n",Ans);
	}
}