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

int n,maxa,cho;
int a[200005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) if(a[i]>maxa) maxa=a[i],cho=i;
	for(int i=2;i<cho;i++) if(a[i]<a[i-1]) return printf("NO\n"),0;
	for(int i=cho+1;i<n;i++) if(a[i]<a[i+1]) return printf("NO\n"),0;
	printf("YES\n");
	return 0;
}