#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define D(...) fprintf(stderr,__VA_ARGS__)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<double>VD;
const int N=500005;
int n,k,cnt;map<PII,int>mp;VD a[N],ans;
void sol(VD&a){
	int kk=k>>1;
	sort(ALL(a));
	int j=0;
//	for(auto x:a)cerr<<x<<" ";D("\n");
	rep(i,1,min(kk,SZ(a))){
		++j;
		ans.PB((k-j*2+1)*a[SZ(a)-i]);
//		cerr<<"! "<<(k-j*2+1)*a[SZ(a)-i]<<endl;
	}
	double s=0;
	rep(i,kk+1,min(k,SZ(a))){
		ans.PB((k-kk*2-1)*a[i-kk-1]-2.*s);
		s+=a[i-kk-1];
	}
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		int x,y;scanf("%d%d",&x,&y);
		if(!x&&!y){
			a[++cnt]={sqrt(x*x+y*y)};
			continue;
		}
		int xx=x,yy=y;
		int g=abs(__gcd(x,y));
		x/=g,y/=g;
		if(!mp[MP(x,y)])mp[MP(x,y)]=++cnt;
		a[mp[MP(x,y)]].PB(sqrt(1.*xx*xx+1.*yy*yy));
	}
	rep(i,1,cnt)sol(a[i]);
	sort(ALL(ans));
	reverse(ALL(ans));
	double res=0;
	rep(i,0,k-1)res+=ans[i];
	printf("%.20f\n",res);
	return 0;
}