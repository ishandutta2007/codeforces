#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9+7;
const int N = 1e5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k, a[N+5], p[N+5], cnt[N+5];
LL pw[N+5];

int calc(int x){
	int res = 1;
	while(x>1){
		int y = p[x], tot = 0;
		while(x%y==0){
			x/=y; ++tot;
		}
		rep(i,1,(tot+k-1)/k) res *= y;
	}
	return res;
}

int main(){
	//freopen("test.in","r",stdin);
	memset(cnt,0,sizeof cnt);
	
	rep(i,1,N) p[i] = i;
	rep(i,2,N) if(p[i]==i)
		for(int j=i+i;j<=N;j+=i) p[j] = i;
	
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",a+i);
	rep(i,1,N){
		pw[i] = 1;
		rep(j,1,k){
			pw[i] = pw[i] * i;
			if(pw[i]>10ll*N*N){
				pw[i] = 10ll*N*N;
				break;
			}
		}
	}
	
	LL ans = 0;
	rep(i,1,n){
		int mi = calc(a[i]);
		//cout<<a[i]<<" "<<mi<<endl;
		for(int j=mi;j<=100000 && pw[j]<=100000ll*a[i];j+=mi){
			if(pw[j]%a[i]!=0) cout<<"!!!!!!!!!!1\n"; 
			//cout<<i<<" "<<j<<" "<<pw[j]<<" "<<a[i]<<" "<<pw[j]/a[i]<<endl;
			ans = ans + cnt[pw[j]/a[i]];
		}
		++cnt[a[i]];
	}
	cout<<ans<<endl;
	return 0;
}