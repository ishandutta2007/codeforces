#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=300007;
const int mod=998244353;
struct arr{
	int x,y;
	friend bool operator<(arr u,arr v){
		if (u.x<v.x){
			return 1;
		}
		else{
			if (u.x>v.x){
				return 0;
			}
			else{
				return u.y<v.y;
			}
		}
	}
}e[maxn];

int tx[maxn],ty[maxn];
int ans=0,n; 

int fac(int n){
	int ans=1;
	for (int i=1;i<=n;++i){
		ans=(ans*i)%mod;
	}
	return ans;
}

int calc(int a[]){
	int ans=1,i=1;
	while (i<=n){
		int tmp=1;
		while (i<n&&a[i+1]==a[i]){
			i++,tmp++;
		}
		ans=(ans*fac(tmp))%mod;
		i++;
	}
	return ans;
}

bool ck(){
	for (int i=1;i<n;++i){
		if (e[i].y>e[i+1].y) return 0;
	}
	return 1;
}
int calc_d(){
	int i=1,ans=1;
	while (i<=n){
		int tmp=1;
		while (i<n&&e[i].x==e[i+1].x&&e[i].y==e[i+1].y){
			i++,tmp++;
		}
		ans=(ans*fac(tmp))%mod;
		i++;
	}
	if (!ck()){
		return 0;
	}
	return ans;
}
#undef int
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>e[i].x>>e[i].y;
		tx[i]=e[i].x,ty[i]=e[i].y;
	}
	sort(tx+1,tx+n+1);
	sort(ty+1,ty+n+1);
	sort(e+1,e+n+1);
	ans=((fac(n)-calc(tx)-calc(ty)+calc_d())%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}