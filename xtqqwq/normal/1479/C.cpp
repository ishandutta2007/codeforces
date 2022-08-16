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

struct node{
	int x,y,z;
	node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
};

int l,r;
vector<node> ans;

int main(){
	l=readint(); r=readint();
	int d=l-1,now=1,st=1;
	r-=d;
	if(d) ans.pb(node(1,2,d)),now=2,st=2;
	while(r>1){
		int mid=r/2;
		for(int j=st;j<=now;j++) ans.pb(node(j,now+1,mid));
		now++;
		if(r&1) ans.pb(node(now,31,r-mid-1));
		r=mid;
	}
	ans.pb(node(31,32,1));
	for(int i=st;i<=now;i++) ans.pb(node(i,32,1));
	printf("YES\n");
	printf("%d %d\n",32,ans.size());
	for(auto r:ans) printf("%d %d %d\n",r.x,r.y,r.z);
	return 0;
}