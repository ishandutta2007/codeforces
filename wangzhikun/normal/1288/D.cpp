#include <bits/stdc++.h>
 
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
 
int n,m,a[300030][10];
 
int val[256],exi[256];
int ansl,ansr;
 
bool chk(int num){
	memset(exi,0,sizeof(exi));
	for(int i=0;i<n;i++){
		int cv = 0;
		for(int j=0;j<m;j++) if(a[i][j]>=num)cv|=1<<j;
		for(int k=cv;k;k = (k-1)&cv){
			exi[k] = 1;
			val[k] = i;
		}
	}
	exi[0] = 1;
	val[0] = 0;
	for(int i=0;i<n;i++){
		int cv = 0;
		for(int j=0;j<m;j++) if(a[i][j]>=num)cv|=1<<j;
		int req = ((1<<m)-1)^cv;
		if(exi[req]){
			ansl = i;
			ansr = val[req];
			return true;
		}
	}
	return false;
}
 
int main() {
	read(n);read(m);
	int l = 0,r = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			read(a[i][j]);
			r = max(r,a[i][j]);
		}
	}
	r+=1;
	while(l+1!=r){
		int mid = (l+r)/2;
		if(chk(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	chk(l);
	cout<<ansl+1<<' '<<ansr+1<<endl;
	return 0;
}