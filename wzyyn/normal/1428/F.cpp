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
const int N=1000005;
char s[N];
int fa[N],sz[N],la[N]; 
int pr[N],su[N],n;
vector<int> op[N];
ll ss[N],sum;
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
ll S(int x,int T){
	return ss[x+T-1]-(x?ss[x-1]:0);
}
void merge(int x,int y,int T){
	if (x<1||y>n) return;
	//cout<<"M "<<x<<' '<<y<<' '<<T<<endl;
	x=get(x); y=get(y);
	if (x==y) return;
	sz[x]+=la[x]-T; la[x]=T;
	sz[y]+=la[y]-T; la[y]=T;
	sum+=S(sz[x],T);
	sum+=S(sz[y],T);
	sz[x]+=sz[y]; fa[y]=x;
	sum-=S(sz[x],T);
}
void change(int x,int T){
	//cout<<"C "<<x<<' '<<T<<endl;
	if (x==-1) return;
	x=get(x);
	sz[x]+=la[x]-T; la[x]=T;
	//cout<<"C "<<x<<' '<<T<<' '<<sz[x]<<endl;
	sum+=S(sz[x],T);
	--sz[x];
	sum-=S(sz[x],T);
}
int main(){
	scanf("%d%s",&n,s+1);
	For(i,1,N-1) ss[i]=ss[i-1]+1ll*(i+1)*i/2;
	pr[0]=su[n+1]=-1;
	For(i,1,n) pr[i]=(s[i]=='0'?i:pr[i-1]);
	Rep(i,n,1) su[i]=(s[i]=='0'?i:su[i+1]);
	For(i,1,n){
		fa[i]=i; la[i]=n;
		sz[i]=(s[i]=='0');
		if (s[i]=='0') sum-=S(1,n);
	}
	For(i,2,n)
		if (s[i]=='0'&&s[i-1]=='0')
			merge(i-1,i,n);
	int la=0;
	For(i,1,n)
		if (s[i]=='0'){
			if (la) op[la].PB(i),la=0;
		}
		else ++la;
	For(i,1,n){
		//cout<<i<<' '<<sum<<endl;
		int l=n-i;
		for (auto j:op[i])
			merge(j-i-1,j,l);
		change(pr[i],l);
		change(su[n-i+1],l);
	}
	cout<<sum+ss[n]<<endl;
}
/*
1 2 3 4
1 1 2 3
*/