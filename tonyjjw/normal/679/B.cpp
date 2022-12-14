//*
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 20;

ll v[MN];

ll f(ll a){
	return 3*a*a + 3*a + 1;
}
ll trace(ll lim,int a){
	if(a==0)return 0;
	
	ll l=1,r=1000000,m,p=-1;
	while(l<=r){
		m=(l+r)>>1;
		if(m*m*m<=lim-v[a-1]){
			l=m+1;
			p=m;
		}
		else r=m-1;
	}
	return p*p*p + trace(min(lim-p*p*p,f(p)-1),a-1);
}

int main(){
	v[0] = 0;
	for(int i=1;i<MN;i++){
		ll l=1, r=1000000, m, p=-1;
		while(l<=r){
			m=(l+r)>>1;
			if(f(m)>v[i-1]){
				r=m-1;
				p=m;
			}
			else{
				l=m+1;
			}
		}
		v[i] = v[i-1] + p*p*p;
	}
	ll m;
	scanf("%lld",&m);
	int ans=-1;
	for(int i=1;i<=18;i++){
		if(v[i]<=m) ans=i;
		else break;
	}
	printf("%d %lld\n",ans,trace(m,ans));
	return 0;
}
//*/