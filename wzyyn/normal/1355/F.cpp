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
int fl[1005],q[1005];
ll qq[1005];
void init(){
	int upb=1000; 
	For(i,2,upb) For(j,2,upb/i) fl[i*j]=1;
	For(i,2,upb) if (!fl[i]){
	    int lim=(i<=100?i*1000:1000);
		for (q[++*q]=1;q[*q]*i<=lim;q[*q]*=i); 
	}
	ll v=1,T=1;
	For(i,1,*q){
		if (1e18/v<q[i]) qq[++*qq]=v,v=1,++T;
		//if (T==22) cout<<q[i]<<endl;
		v*=q[i];
	}
	//cout<<T<<endl;
}
void Axiba(){
	int ans=1;
	For(i,1,22){
		printf("? %lld\n",qq[i]);
		fflush(stdout);
		int v;
		scanf("%d",&v);
		For(j,2,1000) if (!fl[j]){
			int sum=1;
			for (;v%j==0;v/=j,++sum);
			ans*=sum;
		}
	}
	if (ans<=4) printf("! %d\n",8);
	else printf("! %d\n",ans*2);
	fflush(stdout);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) Axiba();
}