#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=300005;
struct P{
	ll x,y;
	P operator -(const P &a)const{
		return (P){x-a.x,y-a.y};
	}
	double operator *(const P &a)const{
		return 1.0*x*a.y-1.0*y*a.x;
	}
	ll F(ll K,ll B){
		return x*K+y+B;
	}
}p[N];
int n,Q,top;
ll K,B;
int main(){
	scanf("%d%d",&n,&Q);
	p[1]=(P){0,0}; top=1;
	while (Q--){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if (tp==1){
			top=1; K=B=0; n+=x;
			p[1]=(P){0,0};
		}
		else if (tp==2){
			P tmp=(P){n,-(n*K+B)};
			for (;top>1&&(p[top]-p[top-1])*(tmp-p[top-1])<=0;top--);
			p[++top]=tmp; n+=x;
		}
		else{
			scanf("%d",&y);
			B+=x; K+=y;
		}
		for (;top>1&&p[top].F(K,B)>=p[top-1].F(K,B);--top);
		printf("%lld %lld\n",p[top].x+1,p[top].F(K,B));
	}
}