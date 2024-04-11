#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,m,Q;
long long a[N],b[N];
long long t1[N],t2[N];
void change(int i,long long v,long long* t){
	for (;i<=m;i+=i&(-i)) t[i]+=v;
}
long long ask(int i,long long* t){
	long long s=0;
	for (;i;i-=i&(-i)) s+=t[i];
	return s;
}
void change(int i,long long v){
	change(i,v,t1);
	change(i,i*v,t2); 
}
int find(long long v){
	int p=0;
	for (int d=1<<16;d;d>>=1)
		if (p+d<m&&t1[p+d]<v)
			p+=d,v-=t1[p];
	return p+1;
}
long long get(int i){
	return b[1]+i*ask(i-1,t1)-ask(i-1,t2);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	long long sb=0;
	for (int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
		sb+=b[i];
	}
	b[0]=b[1];
	for (int i=2;i<=m;i++)
		change(i-1,b[i]-2*b[i-1]+b[i-2]);
	while (Q--){
		int tp,x,v;
		scanf("%d%d%d",&tp,&x,&v);
		if (tp==1){
			for (int i=1;i<=x;i++)
				a[n-x+i]+=i*v;
		}
		else{
			sb+=1ll*x*(x+1)/2*v;
			if (x==m) b[1]+=v,--x;
			change(m-x,v);
		}
		long long ans=sb;
		int la=1;
		for (int i=2;i<=n;i++){
			int no=find(a[i]-a[i-1]);
			ans+=1ll*(no-la+1)*a[i-1]+get(no);
			la=no;
		}
		ans+=(m-la+1)*a[n];
		printf("%lld\n",ans);
	}
}