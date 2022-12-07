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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=100005;
int n,m,k,top,a[N];
pii op[N*3];
int main(){
	scanf("%d%*d%d%d",&n,&m,&k);
	k--; m/=2;
	if (!k){
		return puts("0 0\n"),0;
	}
	For(i,1,n){
		int x;
		scanf("%*d%d",&x); a[i]=(x%=m);
		int l=(x+1)%m,r=(x+k)%m;
		//cout<<l<<' '<<r<<endl;
		op[++top]=pii(l,1);
		op[++top]=pii(r+1,-1);
		if (l>r) op[++top]=pii(0,1);
	}
	op[++top]=pii(m,0);
	sort(op+1,op+top+1);
	int mnv=1<<30,mnp=0,s=0;
	For(i,1,top-1){
		s+=op[i].se;
		if (op[i].fi!=op[i+1].fi){
			//cout<<op[i].fi<<' '<<s<<endl;
			if (s<mnv) mnv=s,mnp=op[i].fi;
		}
	}
	cout<<mnv<<' '<<mnp<<endl;
	For(i,1,n){
		int d=(mnp+m-a[i])%m;
		if (d>=1&&d<=k) cout<<i<<' ';
	}
}