// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[200005],num[200005],now[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=0;i<=n;i++) num[i]=0;
		for(int i=1;i<=n;i++) num[a[i]]++;
		int pl=0;
		for(int i=0;i<=n;i++){
			if(!num[i]){
				pl=i;
				break;
			}
		}
		for(int i=0;i<=n;i++) now[i]=0;
		int th=1;
		vector<int> ans(0);
		while(th<=n){
			int bef=0,cnt=0;
			for(int i=th;i<=n;i++){
				if(!now[a[i]]&&a[i]<pl) cnt++;
				now[a[i]]++;
				if(cnt>=pl){
					bef=i;
					break;
				}
			}
			ans.pb(pl);
			for(int i=th;i<=bef;i++){
				now[a[i]]--;
				num[a[i]]--;
				if(!num[a[i]]) chkmin(pl,a[i]);
			}
			th=bef+1;
		}
		printf("%d\n",ans.size());
		for(auto r:ans) printf("%d ",r);
		printf("\n");
	}
	return 0;
}