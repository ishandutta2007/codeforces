#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
int n,m,s;
int mat[N];
ll t,T[N];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%lld",&s,&t);
	for (;t%n;s=(s+n+(s<=m?t:-t)%n-1)%n+1,t--);
	for (;t;t-=n){
		if (mat[s]){
			if (!T[s]) T[s]=t/n;
			else if (t/n>n) t=((t/n-1)%(T[s]-t/n)+1)*n;
			s=mat[s];
		}
		else{
			int p=s;
			Rep(i,n,1) s=(s+n+(s<=m?i:-i)%n-1)%n+1;
			mat[p]=s;
		}
	}
	printf("%d",s);
}