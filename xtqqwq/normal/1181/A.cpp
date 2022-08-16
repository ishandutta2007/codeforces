#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll x,y,z;

int main(){
	x=readint(); y=readint(); z=readint();
	cout<<(x+y)/z<<' ';
	if(x/z+y/z==(x+y)/z) cout<<0<<endl;
	else cout<<min(z-x%z,z-y%z)<<endl;
	return 0;
}