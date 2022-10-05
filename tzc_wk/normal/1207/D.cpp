#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define int long long
const int MOD=998244353;
int f[300005];
int n,a[300005],b[300005];
pair<int,int> p[300005];
inline void init(){
	f[0]=1;
	for(int i=1;i<=300000;i++)	f[i]=f[i-1]*i%MOD;
}
signed main(){
	init();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		p[i].first=a[i];
		p[i].second=b[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(p+1,p+1+n);
	int tot=f[n];
	int mul1=1,mul2=1,mul3=1,cnt=1;
	for(int i=1;i<=n+1;i++){
		if(a[i]!=a[i-1]){
			mul1=mul1*f[cnt]%MOD;
			cnt=1;
		}
		else
			cnt++;
	}
	cnt=1;
	for(int i=1;i<=n+1;i++){
		if(b[i]!=b[i-1]){
			mul2=mul2*f[cnt]%MOD;
			cnt=1;
		}
		else
			cnt++;
	}
	p[n+1]={0x3f3f3f3f,0x3f3f3f3f};
	int mx=0;
	cnt=1;
	for(int i=1;i<=n+1;i++){
		if(p[i]!=p[i-1]){
			if(p[i].second<mx)	mul3=0;
			mul3=mul3*f[cnt]%MOD;
			cnt=1;
		}
		else
			cnt++;
		mx=max(mx,p[i].second);
	}
	cout<<(tot-mul1-mul2+mul3+MOD*10)%MOD<<endl;
	return 0;
}