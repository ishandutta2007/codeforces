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
ll a[10],b[10],G1,G2;
vector<pll> q1,q2;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
void getopt(ll *a,vector<pll> &vec){
	for (;;){
		sort(a+1,a+4+1);
		if (a[4]-a[1]==1) break;
		ll P=-(1ll<<60);
		for (;;){
			if (a[2]*4>=a[1]*3+a[4]&&a[2]*4<=a[1]+a[4]*3) P=a[2];
			if (a[3]*4>=a[1]*3+a[4]&&a[3]*4<=a[1]+a[4]*3) P=a[3];
			//printf("%lld\n",a[2]);
			if (P!=-(1ll<<60)) break;
			ll v1=min(a[2]-a[1],a[4]-a[2]);
			ll v2=min(a[3]-a[1],a[4]-a[3]);
			if (v1>v2) swap(v1,v2),swap(a[2],a[3]);
			int id1=3,id2=(a[4]-a[3]<a[3]-a[1]?4:1);
			if (id1>id2) swap(id1,id2);
			if (a[4]-a[2]<a[2]-a[1]) swap(id1,id2);
			//cerr<<id1<<' '<<id2<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4]<<endl;
			vec.PB(pll(a[2],a[id1])); a[2]=2ll*a[id1]-a[2];
			vec.PB(pll(a[2],a[id2])); a[2]=2ll*a[id2]-a[2];
			//while(1);
		}
		if (2*P<=a[1]+a[4]){
			For(i,1,4) if (a[i]<P){
				vec.PB(pll(a[i],P));
				a[i]=2ll*P-a[i];
			}
		}
		else{
			For(i,1,4) if (a[i]>P){
				vec.PB(pll(a[i],P));
				a[i]=2ll*P-a[i];
			}
		}
	}
	sort(a+1,a+4+1);
	if (a[1]&1)
		For(i,1,4) if (a[i]&1){
			vec.PB(pll(a[i],a[i]+1));
			a[i]+=2;
		}
	sort(a+1,a+4+1);
}
int main(){
	For(i,1,4) scanf("%lld",&a[i]);
	For(i,1,4) scanf("%lld",&b[i]);
	sort(a+1,a+4+1);
	sort(b+1,b+4+1);
	For(i,2,4) G1=gcd(G1,a[i]-a[1]);
	For(i,2,4) G2=gcd(G2,b[i]-b[1]);
	if (G1!=G2) return puts("-1"),0;
	if (!G1) return puts(a[1]==b[1]?"0":"-1"),0;
	//puts("233");
	if ((a[1]-b[1])%G1) return puts("-1"),0;
	//puts("233");
	ll G=G1,rem=(a[1]%G+G)%G;
	For(i,1,4) a[i]=(a[i]-rem)/G;
	For(i,1,4) b[i]=(b[i]-rem)/G;
	getopt(a,q1);
	getopt(b,q2);
	//For(i,1,4) printf("%lld %lld\n",a[i],b[i]);
	For(i,1,4)
		if ((a[i]&1)!=(b[i]&1))
			return puts("-1"),0;
	//cerr<<233<<endl;
	ll d=(b[1]-a[1])/2;
	for (;3*(a[4]-a[1])<=abs(d);){
		q1.PB(pll(a[3],a[1])); a[3]=2*a[1]-a[3];
		q1.PB(pll(a[2],a[4])); a[2]=2*a[4]-a[2];
		sort(a+1,a+4+1);
	}
	for (;;){
		for (;abs(d)>=a[4]-a[1];)
			if (d<0){
				d+=a[4]-a[1];
				For(T,1,2){
					For(i,2,4){
						q1.PB(pll(a[i],a[1]));
						a[i]=2ll*a[1]-a[i];
					}
					sort(a+1,a+4+1);
				}
			}
			else{
				d-=a[4]-a[1];
				For(T,1,2){
					For(i,1,3){
						q1.PB(pll(a[i],a[4]));
						a[i]=2ll*a[4]-a[i];
					}
					sort(a+1,a+4+1);
				}
			}
		if (a[4]-a[1]<=1) break;
		q1.PB(pll(a[1],a[2])); a[1]=2ll*a[2]-a[1];
		q1.PB(pll(a[4],a[3])); a[4]=2ll*a[3]-a[4];
		sort(a+1,a+4+1);
	}
	//printf("%d %d\n",q1.size(),q2.size());
	Rep(i,q2.size()-1,0)
		q1.PB(pll(2*q2[i].se-q2[i].fi,q2[i].se));
	//printf("%d\n",q1.size());
	int top=0;
	For(i,0,q1.size()-1){
		q1[top].fi=q1[i].fi*G+rem;
		q1[top].se=q1[i].se*G+rem;
		if (q1[top].fi!=q1[top].se) ++top;
	}
	printf("%d\n",top);
	For(i,0,top-1)
		printf("%lld %lld\n",q1[i].fi,q1[i].se);
}
/*
-1 -2 -1 -2
*/