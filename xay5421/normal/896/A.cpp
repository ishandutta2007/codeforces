#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const string A="What are you doing while sending \"";
const string B="\"? Are you busy? Will you send \"";
const string C="\"?";
const string f0="What are you doing at the end of the world? Are you busy? Will you save us?";
using LL=long long;
const int N=100005;
int Q;
LL ll[N];
// fi= "What are you doing while sending \"fi-1\"? Are you busy? Will you send \"fi-1\"?"
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	ll[0]=SZ(f0);
	rep(i,1,N-1){
		ll[i]=SZ(A)+ll[i-1]+SZ(B)+ll[i-1]+SZ(C);
		if(ll[i]>2e18)ll[i]=2e18;
	}
	scanf("%d",&Q);
	while(Q--){
		int n;
		LL k;
		scanf("%d%lld",&n,&k),--k;
		if(k>=ll[n]){
			putchar('.');
			continue;
		}
		per(i,n,0){
			assert(k<ll[i]);
			if(i==0){
				putchar(f0[k]);
				break;
			}
			if(k<SZ(A)){
				putchar(A[k]);
				break;
			}else if(k<SZ(A)+ll[i-1]){
				k-=SZ(A);
			}else if(k<SZ(A)+ll[i-1]+SZ(B)){
				putchar(B[k-SZ(A)-ll[i-1]]);
				break;
			}else if(k<SZ(A)+ll[i-1]+SZ(B)+ll[i-1]){
				k-=SZ(A)+ll[i-1]+SZ(B);
			}else{
				putchar(C[k-SZ(A)-ll[i-1]-SZ(B)-ll[i-1]]);
				break;
			}
		}
	}
	return 0;
}