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
ll f[10005][10],q[10005];
ll solve(ll k,int d){
	if (d==1) return min(10000ll,k);
	int tmp=min(10000ll,k);
	if (f[tmp][d]) return f[tmp][d];
	ll ans=0;
	ll T=min(10000ll,k)+1;
	For(i,1,T){
		ans+=solve(k+ans,d-1);
		if (i!=T) ++ans;
	}
	//cout<<k<<' '<<d<<' '<<k+ans<<endl;
	return f[tmp][d]=ans;
}
void query(ll k,ll d){
	if (d==1){
		int len=min(10000ll,k);
		printf("%d",len);
		For(i,1,len)
			printf(" %lld",k+i-1);
		exit(0); 
	}
	int T=min(10000ll,k);
	ll ans=0; q[0]=k-1;
	printf("%d",T);
	For(i,1,T){
		q[i]=k+(ans+=solve(k+ans,d-1));
		printf(" %lld",q[i]);
		++ans;
	}
	puts("");
	fflush(stdout);
	int v;
	scanf("%d",&v);
	if (v==-1) exit(0);
	query(q[v]+1,d-1);
}
int main(){
	solve(1,5);
	query(1,5);
} 
/*
Q5 1
Q4 2
Q5 345
Q3 6
Q5 7-13  15-29  31-61  
Q4     14     30     62 
*/