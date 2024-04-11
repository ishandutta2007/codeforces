#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int T,n,a[200020];
int main() {
	read(T);
	while(T--){
		read(n);
		ll cmx = -10,cmid = -1;
		ll cmi = 1e18,cmiid = -1;
		for(int i=1;i<=n;i++)read(a[i]);
		for(int i=1;i<=n;i++){
			
			if(cmid!=-1 && abs(a[i]-a[cmid])>i-cmid){
				cout<<"YES\n"<<cmid<<' '<<i<<endl;
				goto nxt;
			}
			if(cmiid!=-1 && abs(a[i]-a[cmiid])>i-cmiid){
				cout<<"YES\n"<<cmiid<<' '<<i<<endl;
				goto nxt;
			}
			if(a[i]+i>cmx){
				cmx = a[i]+i;
				cmid = i;
			}
			if(a[i]-i<cmi){
				cmi = a[i]-i;
				cmiid = i;
			}
			
		}
		cout<<"NO\n";
		nxt:;
	}
	return 0;
}

/*
	Do something instead of doing nothing and stay organized
	Check n == 1, array size , -fsanitize=address, -Wshadow
	Whenever stuck for 15 minutes take a break out
*/