#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

vector<PII> dd1,dd2;

bool valid1(int a,int b) {
	if (a==b) return 0;
	if (a<b) swap(a,b);
	if (a<25) return 0;
	if (a==25) {
		return b<=23;
	} else {
		return b==a-2;
	}
}

bool valid2(int a,int b) {
	if (a==b) return 0;
	if (a<b) swap(a,b);
	if (a<15) return 0;
	if (a==15) {
		return b<=13;
	} else {
		return b==a-2;
	}
}

bool win[4][4][211][211];
PII pre[4][4][211][211];
PII ww[222][222];

vector<PII> res;

void construct(int p1,int p2,int s1,int s2) {
	if (p1==0&&p2==0) return;
	auto v=pre[p1][p2][s1][s2];
//	printf("cc %d %d %d %d\n",p1,p2,s1,s2);
	res.pb(v);
	construct(p1-(v.fi>v.se),p2-(v.se>v.fi),s1-v.fi,s2-v.se);
}
int main() {
	for (int i=0;i<=200;i++) {
		for (int j=0;j<=200;j++) if (valid1(i,j)) {
			dd1.pb(mp(i,j));
		}
	}
//	printf("%d %d\n",SZ(dd1),SZ(dd2));
	for (int i=0;i<=200;i++) {
		for (int j=0;j<=200;j++) if (valid2(i,j)) {
			dd2.pb(mp(i,j));
		}
	}

	win[0][0][0][0]=1;
	for (int p1=0;p1<=2;p1++) for (int p2=0;p2<=2;p2++) {
		auto dd=(p1==2&&p2==2)?dd2:dd1;
//		printf("%d %d %d %d\n",p1,p2,SZ(dd1),SZ(dd2));
		for (auto v:dd) {

			if (v.fi>v.se) {
				for (int s1=0;s1+v.fi<=200;s1++) {
					for (int s2=0;s2+v.se<=200;s2++) {
						if (win[p1][p2][s1][s2]) {
							win[p1+1][p2][s1+v.fi][s2+v.se]=1;
							pre[p1+1][p2][s1+v.fi][s2+v.se]=v;
						}
					}
				}
			} else {
				for (int s1=0;s1+v.fi<=200;s1++) {
					for (int s2=0;s2+v.se<=200;s2++) {
						if (win[p1][p2][s1][s2]) {
							win[p1][p2+1][s1+v.fi][s2+v.se]=1;
							pre[p1][p2+1][s1+v.fi][s2+v.se]=v;
						}
					}
				}
			}
		}
	}
	for (int i=0;i<=200;i++) {
		for (int j=0;j<=200;j++) {
			ww[i][j]=mp(-100,-100);
			for (int p1=0;p1<=3;p1++) for (int p2=0;p2<=3;p2++) if ((p1==3||p2==3)&&win[p1][p2][i][j]) {
//				if (win[p1][p2][i][j]) printf("%d %d %d %d\n",p1,p2,i,j);
				ww[i][j]=max(ww[i][j],mp(p1-p2,p2));
			}
		}
	}
	int _,a,b;
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&a,&b);
		if (ww[a][b]==mp(-100,-100)) {
			puts("Impossible");
			continue;
		}
		res.clear();
		construct(ww[a][b].fi+ww[a][b].se,ww[a][b].se,a,b);
		printf("%d:%d\n",ww[a][b].fi+ww[a][b].se,ww[a][b].se);
		reverse(all(res));
		rep(i,0,SZ(res)) {
			printf("%d:%d%c",res[i].fi,res[i].se," \n"[i==SZ(res)-1]);
		}
	}
}