#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=200005;
const int mo=1000000007;
int n;
ll b[N];
int f[N],la[N];
map<ll,int> mp;
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&b[i]),b[i]+=b[i-1];
	mp.clear();
	Rep(i,n,0){
		if (mp.count(b[i]))
			la[i]=mp[b[i]];
		else la[i]=n;
		mp[b[i]]=i;
	}
	memset(f,0,sizeof(f));
	f[1]=1;
	f[la[0]+1]=mo-1;
	For(i,0,n-1){
		f[i+1]=(f[i+1]+f[i])%mo;
		f[la[i]+1]=(f[la[i]+1]+mo-f[i])%mo;
		f[i+1]=(f[i+1]+f[i])%mo;
	}
	cout<<f[n]<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
1 1 1
  1 1 1
    
*/