#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=1000000007;
const int M=2000005;
int n,x,a[M],b[M];
int mn[M],mx[M],t[M];
void init(){
	For(i,2,M-1) if (!mn[i])
		For(j,1,(M-1)/i) if (!mn[i*j])
			mn[i*j]=i;
}
void insert(int x){
	b[++*b]=x;
	for (;x!=1;){
		int v=mn[x],s=0;
		for (;x%v==0;x/=v,++s);
		if (s>mx[v]) mx[v]=s,t[v]=1;
		else if (s==mx[v]) t[v]++;
	}
}
bool check(int x){
	for (;x!=1;){
		int v=mn[x],s=0;
		for (;x%v==0;x/=v,++s);
		if (t[v]==1&&s==mx[v]) return 0;
	}
	return 1;
}
int main(){
	init();
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&x),++a[x];
	For(i,1,M-1) if (a[i]>=2)
		insert(i),insert(i-1);
	Rep(i,M-1,1) if (a[i]==1)
		insert(i-(mx[i]!=0));
	int ans1=1,ans2=0;
	For(i,1,M-1) For(j,1,mx[i])
		ans1=1ll*ans1*i%mo;
	For(i,2,M-1) if (a[i]>=3-(i==2)) ans2=1;
	For(i,1,*b) if (check(b[i])) ans2=1;
	printf("%d\n",(ans1+ans2)%mo);
}