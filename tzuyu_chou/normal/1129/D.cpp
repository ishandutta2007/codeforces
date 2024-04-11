#include<iostream>
#include<set>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int tzu=500;
int bs=350;
int n,k;
int a[100001];
int l[100001];
int p[100001];
int dp[100001];

int v[100001];
int sum[501];
int cnt[501][1001];
int mn[501],mx[501];
int m;
void ref(int bl){
	int curv=tzu;
	for(int i=mn[bl]; i<=mx[bl] ;i++) cnt[bl][i]=0;
	mn[bl]=mx[bl]=tzu;
	for(int i=min(m,bl*bs); i>(bl-1)*bs ;i--){
		curv+=v[i];cnt[bl][curv]+=dp[i-1]; if(cnt[bl][curv]>=mod) cnt[bl][curv]-=mod;
		mn[bl]=min(mn[bl],curv);mx[bl]=max(mx[bl],curv);
	}
	for(int i=mn[bl]+1; i<=mx[bl] ;i++){
		cnt[bl][i]+=cnt[bl][i-1];if(cnt[bl][i]>=mod) cnt[bl][i]-=mod;
	}
	//for(int i=mn[bl]; i<=mx[bl] ;i++){
	//	cout << i-tzu << ' ' << cnt[bl][i] << endl;
	//}
	sum[bl]=curv;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		l[i]=p[a[i]];
		p[a[i]]=i;
	}
	dp[0]=1;
	for(int i=1; i<=n ;i++){
		//cout << "ROUNd " << i << endl;
		m=i;set<int>upd;
		v[i]=1;upd.insert((i-1)/bs+1);
		if(l[i]!=0){
			v[l[i]]=-1;upd.insert((l[i]-1)/bs+1);
			if(l[l[i]]!=0) v[l[l[i]]]=0;upd.insert((l[l[i]]-1)/bs+1);
		}
		//for(int j=1; j<=i ;j++) cout << v[j] << ' ';
		//cout << endl;
		for(auto cur:upd) ref(cur);
		int cb=(i-1)/bs+1;
		int cs=0;
		for(int j=cb; j>=1 ;j--){
			if(tzu+k-cs>=0) dp[i]+=cnt[j][min(mx[j],tzu+k-cs)];
			cs+=sum[j]-tzu;
			if(dp[i]>=mod) dp[i]-=mod;
		}
		//cout << dp[i] << ' ';
		//cout << endl;
	}
	cout << dp[n] << endl;
}