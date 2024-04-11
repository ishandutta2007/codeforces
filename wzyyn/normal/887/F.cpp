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
const int N=500005;
int n,k,a[N],nxt[N];
int q[N],id[N];
bool cmp(int x,int y){
	return a[x]==a[y]?x<y:a[x]<a[y];
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	//swap(id[1],id[2]);
	int t=1; q[1]=n+1; a[n+1]=-1;
	Rep(i,n,1){
		for (;a[q[t]]>=a[i];--t);
		nxt[i]=q[t];
		q[++t]=i;
		//cout<<i<<' '<<nxt[i]<<endl;
	}
	int px=n+1,py=n+1;
	For(i,1,n){
		int x=id[i];
		//cout<<x<<' '<<px<<' '<<py<<endl;
		if (py>x+k) return puts("NO"),0;
		if (px>x+k){
			//puts("233");
			bool flag=1;
			For(j,1,x-1)
				if (nxt[j]-j>k) flag=0;
			puts(flag?"YES":"NO");
			exit(0);
		}
		py=min(py,px-k);
		px=min(px,x);
	}
	puts("YES");
}