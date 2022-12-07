#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=135;
int n,p,q;
uint C[N],tmp[N],ans;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%d%d",&n,&p,&q);
	p=min(p,n-1);
	For(i,0,p){
		For(j,1,i) tmp[j]=n-j+1;
		For(j,1,i){
			uint x=j;
			For(k,1,i){
				uint G=gcd(x,tmp[k]);
				x/=G; tmp[k]/=G;
				if (!x) break;
			}
		}
		C[i]=1;
		For(j,1,i)
			C[i]*=tmp[j];
	}
	For(i,1,q){
		uint tmp=0,v=i;
		For(j,0,p) tmp+=C[j]*v,v*=i;
		ans^=tmp;
	}
	printf("%u\n",ans);
}
/*
ans=For(i,0,p) C[n][p] For(j,0,i) F[i][j]*C[q][j]
*/