#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=300005;
int n,Q,a[N];
char s[N];
const int M=7000005;
int ls[M],rs[M],v[M];
int rt[N],nd;
void insert(int &nk,int k,int l,int r,int p,int vv){
	nk=++nd; ls[nk]=ls[k]; rs[nk]=rs[k];
	if (l==r) return v[nk]=vv,void(0);
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[nk],ls[k],l,mid,p,vv);
	else insert(rs[nk],rs[k],mid+1,r,p,vv);
}
int ask(int k,int l,int r,int p){
	if (l==r) return v[k];
	int mid=(l+r)/2;
	if (p<=mid) return ask(ls[k],l,mid,p);
	return ask(rs[k],mid+1,r,p);
}
void solve(){
	nd=0;
	scanf("%d%d%s",&n,&Q,s+1);
	a[0]=N;
	for (int i=1;i<=n;i++)
		if ((i%2==0)^(s[i]=='-'))
			a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
	rt[n+1]=0;
	for (int i=n;i>=1;i--)
		insert(rt[i],rt[i+1],0,2*N,a[i],i);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if (a[l-1]==a[r]) puts("0");
		else if ((r-l+1)&1){
			int m;
			if (a[l-1]<a[r]) m=(a[l-1]+a[r]+1)/2;
			else m=(a[l-1]+a[r])/2;
			printf("1\n%d\n",ask(rt[l],0,2*N,m));
		}
		else{
			int p1,p2;
			if (a[l-1]<a[r]) p1=a[l-1]+1,p2=(a[l-1]+a[r])/2+1;
			if (a[l-1]>a[r]) p1=a[l-1]-1,p2=(a[l-1]+a[r])/2-1;
			//cout<<p1<<' '<<p2<<' '<<a[l-1]<<' '<<a[r]<<' '<<rt[l]<<endl;
			printf("2\n%d %d\n",ask(rt[l],0,2*N,p1),ask(rt[l],0,2*N,p2));
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}