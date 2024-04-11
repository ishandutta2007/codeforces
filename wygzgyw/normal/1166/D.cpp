#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int q,k;
ll a,b,m,mi[60],ans[60];
ll S[60];
ll D(ll x,ll y) {
	if (x%y==0) return x/y;
	return x/y+1;
}
bool ck() {
	ll s=ans[1];
	for (int i=2;i<=k;i++) {
		if (1<=ans[i]-s&&ans[i]-s<=m) s+=ans[i];
		else return 0;
	} return 1;
}
void solve() {
	ll r,s,tmp,q,v,cnt;
	ll big,small; ans[1]=0;
	if (a==b) { printf("1 %lld\n",a); return; }
	if (b-a<=m)  { printf("2 %lld %lld\n",a,b); return; }
	for (k=3;k<=50;k++) {
		if (b/a<mi[k]) break;
		r=b-mi[k]*a;
		int flag=1;
		//printf("r=%lld\n",r);
		for (int i=2;i<=k;i++) {
			big=min(m,(r-S[k-i])/mi[k-i+1]);
			if (r/m<S[k-i]) small=1;
			else small=max(1LL,D(r-S[k-i]*m,mi[k-i+1]));
			if (small>m||big<1||small>big) { flag=0; break; }
				ans[i]=small; r-=small*mi[k-i+1];
		}
		if (!flag) continue;
		/*for (int i=1;i<=k;i++)
			printf("%lld ",ans[i]);
		printf("\n");*/
		s=0;
		for (int i=2;i<=k;i++) ans[i]+=s,s+=ans[i];
		for (int i=1;i<=k;i++)
			ans[i]+=mi[i]*a;
		if (!ck()) continue;
		printf("%d ",k);
		for (int i=1;i<=k;i++)
			printf("%lld ",ans[i]);
		printf("\n");
		return;
	}
	printf("-1\n");
}
int main() {
//	freopen("1.txt","r",stdin);
	mi[1]=S[1]=1; ll s=1;
	for (int k=2;k<=50;k++)
		mi[k]=s,s+=mi[k],S[k]=S[k-1]+mi[k];
	read(q);
	while (q--) {
		read(a); read(b); read(m);
		solve();
	}
	return 0;
}