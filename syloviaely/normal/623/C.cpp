#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct atom{
	int x,y;
}A[110000];
int compare(atom k1,atom k2){
	return k1.x<k2.x;
}
int n,Lmi[110000],Lma[110000],Rmi[110000],Rma[110000],opp[1100000];
#define sqr(x) (1ll*(x)*(x))
int check(long long lim){
	//cout<<sqr(Lma[n]-Lmi[n])<<" "<<Lma[n]<<" "<<Lmi[n]<<endl;
	if (sqr(Lma[n]-Lmi[n])<=lim||sqr(A[1].x-A[n].x)<=lim) return 1;
//	cout<<"asd"<<endl;
	int now=1;
	for (int i=1;i<=n;i++){
		while (now<=i&&sqr(A[i].x-A[now].x)>lim) now++;
		if (A[i].x<0) continue;
		int pre=now; now=max(now,opp[i]);
		int k1=max(Lma[now-1],Rma[i+1]),k2=min(Lmi[now-1],Rmi[i+1]),k3=max(abs(k1),abs(k2));
	//	cout<<"fa "<<i<<" "<<now<<" "<<k1<<" "<<k2<<" "<<k3<<endl;
		if (sqr(k3)+sqr(A[i].x)<=lim&&sqr(k1-k2)<=lim) return 1;
		now=pre;
	}
	now=n;
	for (int i=n;i;i--){
		while (now>=i&&sqr(A[i].x-A[now].x)>lim) now--;
		if (A[i].x>0) continue;
		int pre=now; now=min(now,opp[i]);
		int k1=max(Lma[i-1],Rma[now+1]),k2=min(Lmi[i-1],Rmi[now+1]),k3=max(abs(k1),abs(k2));
	//	cout<<"fa "<<i<<" "<<now<<" "<<k1<<" "<<k2<<" "<<k3<<endl;
		if (sqr(k3)+sqr(A[i].x)<=lim&&sqr(k1-k2)<=lim) return 1;
		now=pre;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&A[i].x,&A[i].y); 
	}
	sort(A+1,A+n+1,compare); 
	int now=n;
	for (int i=1;i<=n;i++){
		if (A[i].x>0) break;
		while (now>=i&&abs(A[i].x)<abs(A[now].x)) now--;
		opp[i]=now;
	}
	now=1;
	for (int i=n;i;i--){
		if (A[i].x<0) break;
		while (now<=i&&abs(A[i].x)<abs(A[now].x)) now++;
		opp[i]=now;
	}
/*	cout<<"asd"<<endl;
	for (int i=1;i<=n;i++) cout<<A[i].x<<" "<<A[i].y<<endl;
	for (int i=1;i<=n;i++) cout<<opp[i]<<" "; cout<<endl;*/
	Lma[0]=-1e9; Lmi[0]=1e9;
	Rma[n+1]=-1e9; Rmi[n+1]=1e9;
	for (int i=1;i<=n;i++){
		Lma[i]=max(Lma[i-1],A[i].y);
		Lmi[i]=min(Lmi[i-1],A[i].y);
	}
	for (int i=n;i;i--){
		Rma[i]=max(Rma[i+1],A[i].y);
		Rmi[i]=min(Rmi[i+1],A[i].y);
	}
//	cout<<check(400)<<endl; while (1);
	long long l=0,r=1e18,ans=0;
	while (l<r){
		long long mid=(l+r)>>1;
		if (check(mid)){
			r=mid; ans=mid;
		} else l=mid+1;
	}
	printf("%I64d\n",ans);
	return 0;
}