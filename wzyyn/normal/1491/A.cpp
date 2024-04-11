#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
int n,m,a[200005],S;
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) S+=a[i];
	while (m--){
		int tp,x;
		scanf("%d%d",&tp,&x);
		if (tp==1) S-=a[x],S+=(a[x]^=1);
		else puts(x<=S?"1":"0");
	}
}