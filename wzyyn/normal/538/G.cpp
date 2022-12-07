#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=2000005;
int ans1[N],ans2[N];
int n,L;
struct node{
	ll x,y,v;
	bool operator <(const node &a)const{
		if (x==a.x) return y<a.y;
		return x<a.x;
	}
};
void GG(){
	puts("NO");
	exit(0);
}
struct solver{
	int top;
	node q[N/9];
	void insert(ll T,ll v){
		q[++top]=(node){T%L,T/L,v};
	}
	void getans(int *ans){
		q[++top]=(node){0,0,0};
		sort(q+1,q+top+1);
		ll vl=-L,vr=L;
		//puts("233");
		For(i,1,top){
			node x=q[i],y=q[(i==top?1:i+1)];
			//printf("%lld %lld %lld %lld %lld %lld\n",x.x,x.y,x.v,y.x,y.y,y.v);
			if (x.x==y.x){
				ll dif=y.v-x.v,difT=y.y-x.y;
				if (dif%difT) GG();
				vl=max(vl,dif/difT);
				vr=min(vr,dif/difT);
				for (;(vl+L)%2;++vl);
				for (;(vr+L)%2;--vr);
			}
			else{
				ll dif=(y.x-x.x+L)%L;
				ll difT=((y.y-x.y)*L+y.x-x.x-dif)/L;
				//printf("%lld %lld\n",dif,difT);
				for (;vl<=vr;vl++){
					ll D=y.v-x.v-1ll*vl*difT;
					//printf("JUD %lld\n",D);
					if (abs(D)<=dif&&abs(vl-D)<=L-dif&&(vl+L)%2==0) break;
				}
				for (;vl<=vr;vr--){
					ll D=y.v-x.v-1ll*vr*difT;
					if (abs(D)<=dif&&abs(vr-D)<=L-dif&&(vr+L)%2==0) break;
				}
			}
			//printf("%lld %lld\n",vl,vr);
		}
		if ((vl+L)%2) ++vl;
		if ((vr+L)%2) --vr;
		//printf("%lld %lld\n",vl,vr);
		if (vl>vr) GG();
		q[++top]=(node){L,0,vl};
		int p1=0,p2=0;
		For(i,1,top){
			ll q1=q[i].x,q2=q[i].v-q[i].y*vl;
			//printf("%lld %lld\n",q1,q2);
			for (;p1<q1;){
				++p1;
				if (p2<q2) ans[p1]=1,++p2;
				else ans[p1]=-1,--p2;
			}
			if (p2!=q2){
				puts("ANSGG");
				exit(0);
			}
		}
	}
}T1,T2;
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&L);
	For(i,1,n){
		ll T,x,y;
		scanf("%lld%lld%lld",&T,&x,&y);
		T1.insert(T,x+y);
		T2.insert(T,x-y);
	}
	T1.getans(ans1);
	T2.getans(ans2);
	For(i,1,L){
		if (ans1[i]==ans2[i])
			putchar(ans1[i]==1?'R':'L');
		else putchar(ans1[i]==1?'U':'D');
	}
}