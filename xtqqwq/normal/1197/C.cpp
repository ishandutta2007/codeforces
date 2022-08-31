#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
int a[300005],b[300005];

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	sort(b+1,b+n);
	ll sum=a[n]-a[1];
	for(int i=n-1;i>=n-k+1;i--) sum-=b[i];
	cout<<sum<<endl;
	return 0;
}