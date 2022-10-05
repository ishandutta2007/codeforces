#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
ll a,b,c,d;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(b*c<a){puts("-1");continue;}
//		if(c<d){cout<<a<<endl;continue;}
		ll l=1,r=c/d+10; 
		while(l+2<r){
//			printf("%lld %lld\n",l,r);
			ll lmid=(ll)(l+(r-l)/3.0),rmid=ll(r-(r-l)/3.0);
			if(lmid*a-b*d*(lmid-1)*lmid/2<=rmid*a-b*d*(rmid-1)*rmid/2) l=lmid;
			else r=rmid;
		}
//		printf("%lld %lld\n",l,r);
		if(r-l==2){
			cout<<max(max(l*a-b*d*(l-1)*l/2,r*a-b*d*(r-1)*r/2),(l+1)*a-b*d*(l+1)*l/2)<<endl;
		}
		else if(r-l==1){
			cout<<max(l*a-b*d*(l-1)*l/2,r*a-b*d*(r-1)*r/2)<<endl;
		}
		else cout<<l*a-b*d*(l-1)*l/2<<endl;
	}
	return 0;
}
/*
1
1000000 1000000 1000000 1000000
*/