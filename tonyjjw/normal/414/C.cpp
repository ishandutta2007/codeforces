#include<stdio.h>
#include<algorithm>
#define MN (1<<20)

int N,M,NN,depth;
int A[MN],tmp[MN];
long long ans[21],anst[21],same[21];

void merge(int l,int r){
	if(r==l+1)return;
	int m=(l+r)>>1;
	depth--;
	merge(l,m),merge(m,r);
	depth++;
	int p1=l,p2=m,c=0,c1,c2;
	while(p1+p2<m+r){
		if(p1==m){
			tmp[c++]=A[p2++];
		}
		else if(p2==r){
			tmp[c++]=A[p1++];
			ans[depth]+=p2-m;
		}
		else if(A[p1]<=A[p2]){
			if(A[p1]==A[p2]){
				c1=c2=0;
				while(p1+1<m && A[p1]==A[p1+1])tmp[c++]=A[p1++],c1++,ans[depth]+=p2-m;
				tmp[c++]=A[p1++],c1++,ans[depth]+=p2-m;
				while(p2+1<r && A[p2]==A[p2+1])tmp[c++]=A[p2++],c2++;
				tmp[c++]=A[p2++],c2++;
				same[depth]+=(long long)c1*c2;
				continue;
			}
			tmp[c++]=A[p1++];
			ans[depth]+=p2-m;
		}
		else if(A[p1]>A[p2]){
			tmp[c++]=A[p2++];
		}
	}
	for(c=0;c<r-l;c++){
		A[l+c]=tmp[c];
	}
}

int main(){
	int i,j,n;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	NN=(1<<N);
	for(i=0;i<NN;i++){
		scanf("%d",&A[i]);
	}
	depth=N;
	merge(0,NN);
	for(i=1;i<=N;i++)ans[i]+=ans[i-1],same[i]+=same[i-1];
	scanf("%d",&M);
	for(i=0;i<M;i++){
		scanf("%d",&n);
		for(j=0;j<=n;j++){
			anst[j]=(long long)(1<<(N-1))*((1<<j)-1)-ans[j]-same[j];
		}
		for(j=n+1;j<=N;j++){
			anst[j]=(ans[j]-ans[j-1])+anst[j-1];
		}
		for(j=0;j<=N;j++)ans[j]=anst[j];
		printf("%lld\n",ans[N]);
	}
	return 0;
}