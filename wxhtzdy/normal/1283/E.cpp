#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int x[200005],b[200005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) x[i]=readint();
	sort(x+1,x+n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		if(b[x[i]-1]==0) b[x[i]-1]=1;
		else if(b[x[i]]==0) b[x[i]]=1;
		else b[x[i]+1]=1;
	}
	for(int i=0;i<=n+1;i++) if(b[i]!=0) mx++;
	for(int i=0;i<=n+1;i++) b[i]=0;
	for(int i=1;i<=n;i++) b[x[i]]++;
	int mn=0;
	for(int i=1;i<=n;i++){
		if(b[i]>0){
			b[i+1]+=b[i];
			b[i+1]+=b[i+2];
			mn++;
			i+=2;
		}
	}
	printf("%d %d",mn,mx);
	return 0;
}