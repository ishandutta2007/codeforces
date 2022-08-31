#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int cnt[2];

vector<int> ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	vector<int> ret(1,0);
	for(int i=1;i<=n;i++) ret.pb(readint());
	return ret;
}

int main(){
	n=readint();
	vector<int> tmp=ask(1);
	vector<pii> ans;
	for(int i=1;i<=n;i++) cnt[tmp[i]&1]++;
	if(cnt[0]<=cnt[1]){
		for(int i=1;i<=n;i++) if(tmp[i]==1) ans.pb(mp(1,i));
		for(int i=2;i<=n;i++){
			if(tmp[i]%2==0){
				vector<int> vec=ask(i);
				for(int j=1;j<=n;j++) if(vec[j]==1) ans.pb(mp(i,j));
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(tmp[i]%2==1){
				vector<int> vec=ask(i);
				for(int j=1;j<=n;j++) if(vec[j]==1) ans.pb(mp(i,j));
			}
		}
	}
	printf("!\n");
	for(auto r:ans) printf("%d %d\n",r.fi,r.se);
	return 0;
}