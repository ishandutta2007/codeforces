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
int n,m,k,top;
pii op[3005];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int up=4*n*m-2*n-2*m;
	if (up<k) return puts("NO"),0;
	For(i,2,m){
		op[++top]=pii(min(1,k),'R'); k-=op[top].fi;
		op[++top]=pii(min(k,n-1),'D'); k-=op[top].fi;
		op[++top]=pii(min(k,n-1),'U'); k-=op[top].fi;
	}
	op[++top]=pii(min(m-1,k),'L'); k-=op[top].fi;
	For(i,2,n){
		op[++top]=pii(min(1,k),'D'); k-=op[top].fi;
		op[++top]=pii(min(k,m-1),'R'); k-=op[top].fi;
		op[++top]=pii(min(k,m-1),'L'); k-=op[top].fi;
	}
	op[++top]=pii(min(n-1,k),'U'); k-=op[top].fi;
	int tmp=0;
	For(i,1,top) if (op[i].fi) op[++tmp]=op[i];
	printf("YES\n%d\n",tmp);
	For(i,1,tmp) printf("%d %c\n",op[i].fi,op[i].se);
}