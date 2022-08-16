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

int ask(int x){
	if(x==0||x==n+1) return 1e9;
	printf("? %d\n",x);
	fflush(stdout);
	return readint();
}

void answer(int x){
	printf("! %d\n",x);
	fflush(stdout);
}

int main(){
	n=readint();
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		int vl=ask(mid-1),vm=ask(mid),vr=ask(mid+1);
		if(vl>vm&&vr>vm){
			answer(mid);
			return 0;
		}
		if(vl<vm) r=mid-1;
		else l=mid+1;
	}
	return 0;
}