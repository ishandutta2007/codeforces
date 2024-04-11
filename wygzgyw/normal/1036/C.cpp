#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T;
ll L,R,a[20][4],mi[4],c[20][20];
ll s(int cnt,int x,int y) {
	ll res=0;
	for (int i=x;i<=y;i++)
		res+=a[cnt][i];
	return res;
}
ll solve(ll mid,int b) {
	if (mid==0||b==0) return 1;
	if (mid<10) return mid+1;
	ll t=1; int cnt=0;
	for (int i=1;i<=18;i++,cnt++,t*=10)
		if (t>mid/10) break;
	ll res=s(cnt,0,b);
	for (int i=1;i<=9&&i<mid/t;i++) {
		res+=s(cnt,0,b-1);
		//printf("%lld %d\n",mid,i);
	}
	//printf("%lld %lld %lld\n",mid,res,s(cnt+1,0,3));
	res+=solve(mid%t,b-1);
	//printf("%lld %lld\n",mid,res);
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	mi[0]=1;
	for (int j=1;j<=3;j++) mi[j]=mi[j-1]*9;
	for (int i=1;i<=18;i++) {
		c[i][0]=c[i][i]=1;
		for (int j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	for (int i=1;i<=18;i++)
		for (int j=0;j<=3;j++) {
			if (i<j) break;
			a[i][j]=c[i][j]*mi[j];
		}
	read(T);
	while (T--) {
		read(L); read(R);
		printf("%lld\n",solve(R,3)-solve(L-1,3));
	}
	return 0;
}