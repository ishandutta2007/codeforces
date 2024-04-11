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
int mn[N],v[5],top,x;
ll qq[105],ans,n,m;
pii q[105];
void init(){
	For(i,2,N-1) if (!mn[i])
		For(j,1,(N-1)/i) if (!mn[i*j])
			mn[i*j]=i;
}
void Inputv(ll &n){
	int v1,v2,v3;
	scanf("%d%d%d",&v1,&v2,&v3);
	n=1ll*v1*v2*v3;
}
void Inputvv(){
	top=0;
	For(T,1,3){
		int v;
		scanf("%d",&v);
		for (;v!=1;){
			q[++top]=pii(mn[v],1);
			v/=mn[v];
		}
	}
	q[++top]=pii(2,1);
	sort(q+1,q+top+1);
	int tmp=top; top=1;
	For(i,2,tmp)
		if (q[i].fi!=q[i-1].fi)
			q[++top]=q[i];
		else ++q[top].se;
}
void count1(int d,ll v){
	if (d==top+1){
		ans+=(v<=n);
		return;
	}
	For(i,0,q[d].se){
		count1(d+1,v);
		v*=q[d].fi;
	}
}
void count2(int d,ll v,ll fl){
	//cout<<d<<' '<<v<<' '<<fl<<endl;
	if (d==*qq+1){
		ans+=fl*v;
		return;
	}
	count2(d+1,v,fl);
	count2(d+1,v/qq[d],-fl);
}
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
void solve(){
	ans=0; *qq=0; n=1; m=1;
	For(i,1,3) scanf("%d",&v[i]),n*=v[i];
	For(i,1,3) scanf("%d",&x),m*=x;
	Inputvv();
	For(i,1,top){
		ll rem=1;
		For(j,1,q[i].se+1) rem*=q[i].fi;
		For(j,1,3){
			ll G=gcd(v[j],rem);
			v[j]/=G; rem/=G;
		}
		//cout<<i<<' '<<rem<<endl;
		if (rem==1){
			qq[++*qq]=1;
			For(j,1,q[i].se+1) qq[*qq]*=q[i].fi;
			For(j,1,3) for (;v[j]%q[i].fi==0;v[j]/=q[i].fi);
		}
	}
	For(i,1,3)
		for (;v[i]!=1;v[i]/=mn[v[i]])
			qq[++*qq]=mn[v[i]];
	//For(i,1,*qq) cout<<qq[i]<<' '; cout<<endl;
	sort(qq+1,qq+*qq+1);
	*qq=unique(qq+1,qq+*qq+1)-qq-1;
	count1(1,1);
	//printf("ANS=%lld\n",ans);
	count2(1,m,1);
	printf("%lld\n",ans);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
move id2:2s<=n 
move id1:2s%gcd(k,n)==0 
*/