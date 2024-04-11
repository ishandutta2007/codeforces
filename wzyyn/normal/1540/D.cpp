#include<bits/stdc++.h>
using namespace std;

const int N=200005;
const int B=200;
int n,cnt,b[N],Q;
int L[N],R[N],q[5*B+2][B+5],top[N];
int t[N];

void build(int k){
	top[k]=0;
	for (int i=R[k];i>=L[k];i--){
		int p=0,rem=b[i];
		for (int j=1<<16;j;j>>=1)
			if ((p+j)<=n&&j-t[j+p]<rem)
				p+=j,rem-=j-t[p];
		q[k][++top[k]]=++p;
		for (;p<=n;p+=p&(-p)) t[p]++;
	}
	for (int i=1;i<=top[k];i++)
		for (int p=q[k][i];p<=n;p+=p&(-p))
			t[p]=0;
	sort(q[k]+1,q[k]+top[k]+1);
	for (int i=1;i<=top[k];i++) q[k][i]-=i-1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]=i-b[i];
	}
	cnt=(n-1)/B+1;
	for (int i=1;i<=cnt;i++){
		L[i]=(i-1)*B+1;
		R[i]=min(n,i*B);
		build(i);
	}
	scanf("%d",&Q);
	while (Q--){
		int tp,x;
		scanf("%d%d",&tp,&x);
		if (tp==1){
			scanf("%d",&b[x]);
			b[x]=x-b[x];
			build((x-1)/B+1);
		}
		else{
			int be=(x-1)/B+1;
			int ans=b[x];
			for (int i=x+1;i<=R[be];i++)
				if (b[i]<=ans) ++ans;
			for (int i=be+1;i<=cnt;i++)
				ans+=upper_bound(q[i]+1,q[i]+top[i]+1,ans)-q[i]-1;
			printf("%d\n",ans);
		}
	}
}