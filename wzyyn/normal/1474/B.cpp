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
int fl[50005],q[50005];
int main(){
	For(i,2,50000) For(j,2,50000/i) fl[i*j]=1;
	For(i,2,50000) if (!fl[i]) q[++*q]=i;
	int T;
	scanf("%d",&T);
	while (T--){
		int x;
		scanf("%d",&x);
		int y=lower_bound(q+1,q+*q+1,1+x)-q;
		int z=lower_bound(q+1,q+*q+1,q[y]+x)-q;
		printf("%d\n",q[y]*q[z]);
	}
}