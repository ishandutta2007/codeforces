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

int n,m,sa,sb;
int a[1005],b[1005];
bitset<2000001> now[1005];

int main(){
	int T=readint();
	while(T--){
		sa=sb=0;
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint(),sa+=a[i];
		m=readint();
		for(int i=1;i<=m;i++) b[i]=readint(),sb+=b[i];
		if(n!=m||(sa&1)||(sb&1)){
			printf("No\n");
			continue;
		}
		vector<int> a1(0),a2(0),b1(0),b2(0);
		now[0].reset();
		now[0][1000000]=1;
		for(int i=1;i<=n;i++) now[i]=(now[i-1]<<a[i])|(now[i-1]>>a[i]);
		if(now[n][1000000]){
			int num=1000000;
			for(int i=n;i>=1;i--){
				if(num+a[i]>2000000) a1.pb(a[i]),num-=a[i];
				else if(num-a[i]<0) a2.pb(a[i]),num+=a[i];
				else if(now[i-1][num+a[i]]) a2.pb(a[i]),num+=a[i];
				else a1.pb(a[i]),num-=a[i];
			}
		}
		else{
			printf("No\n");
			continue;
		}
		now[0].reset();
		now[0][1000000]=1;
		for(int i=1;i<=n;i++) now[i]=(now[i-1]<<b[i])|(now[i-1]>>b[i]);
		if(now[n][1000000]){
			int num=1000000;
			for(int i=n;i>=1;i--){
				if(num+b[i]>2000000) b1.pb(b[i]),num-=b[i];
				else if(num-b[i]<0) b2.pb(b[i]),num+=b[i];
				else if(now[i-1][num+b[i]]) b2.pb(b[i]),num+=b[i];
				else b1.pb(b[i]),num-=b[i];
			}
		}
		else{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		sort(a1.begin(),a1.end());
		sort(a2.begin(),a2.end());
		sort(b1.begin(),b1.end());
		sort(b2.begin(),b2.end());
		reverse(a1.begin(),a1.end());
		reverse(a2.begin(),a2.end());
		if(b1.size()<a1.size()){
			vector<int> tmp(0);
			for(int i=a1.size()-b1.size();i<b2.size();i++) tmp.pb(b2[i]);
			int tb=b1.size();
			for(int i=0;i<a1.size()-tb;i++) b1.pb(-b2[i]);
			b2=tmp;
			sort(b1.begin(),b1.end());
		}
		else if(b1.size()>a1.size()){
			vector<int> tmp(0);
			for(int i=b1.size()-a1.size();i<b1.size();i++) tmp.pb(b1[i]);
			int tb=a1.size();
			for(int i=0;i<b1.size()-tb;i++) b2.pb(-b1[i]);
			b1=tmp;
			sort(b2.begin(),b2.end());
		}
//		for(auto r:a1) cout<<r<<' ';
//		cout<<endl;
//		for(auto r:a2) cout<<r<<' ';
//		cout<<endl;
//		for(auto r:b1) cout<<r<<' ';
//		cout<<endl;
//		for(auto r:b2) cout<<r<<' ';
//		cout<<endl;
		int nx=0,ny=0;
		for(int i=0;i<a1.size();i++){
			nx+=a1[i];
			printf("%d %d\n",nx,ny);
			ny+=b1[i];
			printf("%d %d\n",nx,ny);
		}
		for(int i=0;i<a2.size();i++){
			nx-=a2[i];
			printf("%d %d\n",nx,ny);
			ny-=b2[i];
			printf("%d %d\n",nx,ny);
		}
	}
	return 0;
}