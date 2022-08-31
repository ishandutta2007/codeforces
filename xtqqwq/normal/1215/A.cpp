#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int a1,a2,k1,k2,n;

int main(){
	a1=readint(); a2=readint(); k1=readint(); k2=readint();
	n=readint();
	cout<<max(0,n-a1*(k1-1)-a2*(k2-1))<<' ';
	if(k1>k2) swap(a1,a2),swap(k1,k2);
	int x=n/k1;
	if(x>a1) x=a1;
	n-=x*k1;
	cout<<x+n/k2<<endl;
	return 0;
}