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
const int N=1000005;
int n,p,a[N],ans[N];
int v1[N],sum[N];
int main(){
	scanf("%d%d",&n,&p);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int v=1,la=1;
	For(i,1,n) v=max(v,a[i]-i+1);
	int pos=0;
	//cout<<v<<endl;
	For(i,0,n*2+3){
		for (;pos!=n&&a[pos+1]<=v;++pos);
		v1[i]=pos%p; v++;
		//cout<<pos<<' ';
		//cout<<endl;
	}
	v-=2*n+4;
	For(i,0,n-1) ++sum[(i%p-v1[i]+p)%p];
	For(i,0,n+2){
		//cout<<i<<' '<<sum[i%p]<<endl;
		if (!sum[i%p]) ans[++*ans]=v+i;
		int p1=i,p2=i+n;
		--sum[(p1%p-v1[p1]+p)%p];
		++sum[(p2%p-v1[p2]+p)%p];
	}
	printf("%d\n",*ans);
	For(i,1,*ans) printf("%d ",ans[i]);
}
/*
pos[i+j]=j%p
i%p-pos[i][j]
*/
/*
p-
*/