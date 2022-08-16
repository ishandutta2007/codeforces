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

int n,m,blo;
ll x[200005],y[200005],s[200005],a[505][505],st[200005];

int main(){
	n=readint(); m=readint();
	blo=sqrt(m);
	for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint();
	int opt,k;
	for(int i=1;i<=m;i++){
		opt=readint(); k=readint();
		if(opt==1){
			if(x[k]+y[k]<=blo){
				int l=(i+x[k])%(x[k]+y[k]),r=i%(x[k]+y[k]);
				for(int j=l;j!=r;j=(j+1)%(x[k]+y[k])) a[x[k]+y[k]][j]++;
			}
			else{
				for(int j=i;j<=m;j+=x[k]+y[k]){
					if(j+x[k]<=m) s[j+x[k]]++;
					if(j+x[k]+y[k]<=m) s[j+x[k]+y[k]]--;
				}
			}
			st[k]=i;
		}
		else{
			if(x[k]+y[k]<=blo){
				int l=(st[k]+x[k])%(x[k]+y[k]),r=st[k]%(x[k]+y[k]);
				for(int j=l;j!=r;j=(j+1)%(x[k]+y[k])) a[x[k]+y[k]][j]--;
			}
			else{
				for(int j=st[k];j<=m;j+=x[k]+y[k]){
					if(j+x[k]<=m){
						if(j+x[k]<i) s[i]--;
						else s[j+x[k]]--;
					}
					if(j+x[k]+y[k]<=m){
						if(j+x[k]+y[k]<i) s[i]++;
						else s[j+x[k]+y[k]]++;
					}
				}
			}
		}
		int ans=0;
		for(int j=2;j<=blo;j++) ans+=a[j][i%j];
		s[i]+=s[i-1];
		ans+=s[i];
		printf("%d\n",ans);
	}
	return 0;
}