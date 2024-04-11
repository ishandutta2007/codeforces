#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
int n,ans;
ll LIS;
vector<ll> a,peaks;
int sgn(ll x) {
	if (x<0) return -1;
	if (x>0) return 1;
	return 0;
}
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int D(int i,int j,vector<int> &res) {
	if (i%2==0) return res[j-i];
	if (j-i-1>=0) return res[j-i-1];
	return 0;
}
vector<int> ksm(int cnt,ll d) {
	if (d==1) return vector<int>(cnt,1);
	vector<int> res=ksm(cnt,d/2);
	vector<int> dp(cnt),dp2(cnt);
	for (int j=0;j<cnt;j++)
	for (int i=0;i<=j;i++) {
		update(dp[j],(ll)D(0,i,res)*D(i,j,res)%mod);
	}
	if (d&1) {
		for (int j=0;j<cnt;j++)
		for (int i=0;i<=j;i++)
			if (i<j||j%2==0)
				update(dp2[j],dp[i]);
		return dp2;
	}
	return dp;
}
vector<ll> L,R;
vector<int> flag,dp;
void trans(ll x) {
	vector<int> dp2; dp2.resize(dp.size());
	for (int i=0;i<dp.size();i++)
	for (int j=0;j<i+(flag[i]==1);j++)
		if (L[i]<=x&&x<=R[i]&&L[j]<=x-1&&x-1<=R[j])
			update(dp2[i],dp[j]);
	dp=dp2;
}
void solve(vector<ll> b) {
	vector<ll> c=b;
	sort(c.begin(),c.end());
	int sz=(int)b.size()-1;
	//for (int i=0;i<sz;i++) printf("%lld ",b[i]); printf("\n");
	L.resize(sz),R.resize(sz),flag.resize(sz),dp.resize(sz);
	for (int i=0;i<sz;i++) {
		L[i]=b[i],R[i]=b[i+1];
		if (i!=0) {
			if (L[i]<R[i]) L[i]++; else L[i]--;
		}
		if (L[i]>R[i]) swap(L[i],R[i]),flag[i]=-1;
		else flag[i]=1;
	}
	for (int i=0;i<sz;i++)
		if (L[i]<=c[0]&&c[0]<=R[i]) dp[i]=1;
	ll lst=c[0],z;
	int cnt; vector<int> id(sz);
	for (ll x : c) {
		z=x-2;
		if (lst<z) {
			vector<int> mk(sz);
			for (int i=0;i<sz;i++)
			for (int j=0;j<i+(flag[i]==1);j++)
				if (L[i]<=z&&z<=R[i]&&L[j]<=z&&z<=R[j]) mk[i]=mk[j]=1;
			cnt=0;
			for (int i=0;i<sz;i++) if (mk[i]) id[i]=cnt++;
			vector<int> res=ksm(cnt,z-lst);
			vector<int> dp2(sz);
			for (int i=0;i<sz;i++)
			for (int j=0;j<=i;j++) update(dp2[i],(ll)dp[j]*D(id[j],id[i],res)%mod);
			dp=dp2;
			lst=z;
		}
		z=x-1;
		if (lst<z) trans(z),lst=z;
		z=x;
		if (lst<z) trans(z),lst=z;
		z=x+1;
		if (lst<z&&z<=c.back()) trans(z),lst=z;
	}
	for (int i=0;i<sz;i++)
		if (L[i]<=c.back()&&c.back()<=R[i]) update(ans,dp[i]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); ll x; read(x);
	for (int i=1;i<=n;i++) {
		read(x); if (!x) continue;
		if (!a.empty()&&sgn(x)==sgn(a.back())) a.back()+=x;
		else a.push_back(x);
	}
	n=(int)a.size();
	peaks.push_back(1);
	for (int i=0;i<n;i++) peaks.push_back(a[i]+peaks.back());
	n++;
	LIS=1;
	for (int i=0;i<n;i++) for (int j=i+1;j<n;j++)
		if (peaks[i]<=peaks[j]) LIS=max(LIS,peaks[j]-peaks[i]+1);
	if (LIS==1) {
		ans=1;
		for (int i=0;i<a.size();i++) update(ans,abs(a[i])%mod);
		printf("1 %d\n",ans);
		return 0;
	}
	int i=0,nxt;
	vector<ll> b;
	while (i<n) {
		nxt=-1;
		for (int j=i+1;j<n;j++) if (peaks[j]-peaks[i]+1==LIS) nxt=j;
		if (nxt==-1) { i++; continue; }
		b.clear();
		for (int j=i;j<=nxt;j++) b.push_back(peaks[j]);
		solve(b);
		i=nxt;
	}
	printf("%lld %d\n",LIS,ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/