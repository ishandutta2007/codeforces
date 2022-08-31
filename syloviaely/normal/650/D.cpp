#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct ask{
	int where,w,num;
}q[410000];
int A[810000],cnt,x[410000],n,m,L[410000],R[410000],Lway[410000],Rway[410000],ans[410000],N,lans[410000],rans[410000];
int get(int w){
	int l=1,r=cnt+1,ans=0;
	while (l<r){
		int mid=l+r>>1;
		if (A[mid]<=w){
			ans=mid; l=mid+1;
		} else r=mid;
	}
	return ans;
}
int compare(ask k1,ask k2){
	return k1.where>k2.where;
}
void insert(int *w,int k1,int where){
	for (;k1<=cnt;k1+=k1&(-k1)) if (w[A[k1]]<=w[where]) A[k1]=where;
}
int find(int *w,int k1){
	int ans=0;
	for (;k1;k1-=k1&(-k1)) if (w[A[k1]]>w[ans]||(w[A[k1]]==w[ans]&&A[k1]<ans)) ans=A[k1];
	return ans;
}
void get(int *an,int *way,int *pa){
	memset(A,0x00,sizeof A);
	sort(q+1,q+m+1,compare); int now=1;
//	cout<<"start"<<endl;
//	for (int i=1;i<=n;i++) cout<<x[i]<<" "; cout<<endl;
	N=0;
	for (int i=n;i;i--){
		int k1=find(an,cnt-x[i]); way[i]=k1; an[i]=an[k1]+1; N=max(an[i],N);
		while (now<=m&&q[now].where==i){
			int k1=find(an,cnt-q[now].w); ans[q[now].num]+=an[k1]; //cout<<"fa "<<q[now].num<<" "<<k1<<" "<<an[k1]<<endl; 
			now++;
		}
		insert(an,cnt-x[i]+1,i);
	}
	for (int i=1;i<=n;i++)
		if (an[i]==N){
			pa[1]=i;
			for (int j=2;j<=N;j++) pa[j]=way[pa[j-1]]; return;
		}
}
int main(){
	scanf("%d%d",&n,&m); cnt=0;
	for (int i=1;i<=n;i++) scanf("%d",&x[i]),A[++cnt]=x[i];
	for (int i=1;i<=m;i++) scanf("%d%d",&q[i].where,&q[i].w),A[++cnt]=q[i].w,q[i].num=i;
	sort(A+1,A+cnt+1); int pre=cnt; cnt=1;
	for (int i=2;i<=pre;i++) if (A[i]!=A[cnt]) A[++cnt]=A[i];
	for (int i=1;i<=n;i++) x[i]=get(x[i]);
	for (int i=1;i<=m;i++) q[i].w=get(q[i].w);
	//for (int i=1;i<=n;i++) cout<<x[i]<<" "; cout<<endl;
	//for (int i=1;i<=m;i++) cout<<q[i].w<<" "; cout<<endl;
	memset(A,0x00,sizeof A);
	get(L,Lway,lans); 
	for (int i=1;i<=n;i++) if (i<=n-i+1) swap(x[i],x[n-i+1]);
	for (int i=1;i<=n;i++) x[i]=cnt-x[i]+1;
	for (int i=1;i<=m;i++) q[i].where=n-q[i].where+1,q[i].w=cnt-q[i].w+1;
	get(R,Rway,rans);
//	for (int i=1;i<=n;i++) cout<<L[i]<<" "; cout<<endl;
//	for (int i=1;i<=n;i++) cout<<R[i]<<" "; cout<<endl;
	for (int i=1;i<=m;i++){
		int k1=q[i].num; ans[k1]++;
		int k2=q[i].where,k3=R[k2];
		if (rans[N-k3+1]==k2&&lans[k3]==n-k2+1) ans[k1]=max(ans[k1],N-1); else ans[k1]=max(ans[k1],N);
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}