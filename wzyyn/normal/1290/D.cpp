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
const int N=3005;
const int type=0;
int vis[N],a[N],q[N*N],S[N];
int n,k,kk,w,ans,h,t,times;
void init(){
	kk=k;
	For(i,1,n){
		a[i]=rand()%n+1;
		if (!S[a[i]]) ++w;
		S[a[i]]=1;
	}
	memset(S,0,sizeof(S));
}
int Q(int x){
	++times;
	if (type==0){
		printf("? %d\n",x);
		fflush(stdout);
		char s[5];
		scanf("%s",s+1);
		return s[1]=='Y';
	}
	else{
		q[++t]=a[x];
		++S[a[x]];
		int res=(S[a[x]]>1);
		if (t-h>kk){
			++h; --S[q[h]];
		}
		return res;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	if (type==1) init();
	int ans=n;
	if (k==1){
		For(i,1,n) For(j,i+1,n){
			Q(i);
			if (Q(j)&&!vis[j])
				ans--,vis[j]=1;
		}
	}
	else if (k==n){
		For(i,1,n)
			if (Q(i))
				--ans;
	}
	else{
		k/=2;
		//For(i,1,n) if (Q(i))
		//	ans--,vis[i]=1;
		int blk=n/k;
		For(i,1,blk) For(j,0,i-1){
			if (j+i>=blk) continue;
			if (type==0){
				printf("R\n");
				fflush(stdout);
			}
			else{
				h=t=0;
				memset(S,0,sizeof(S));
			}
			int x=j;
			for (;x<blk;x+=i) For(j,1,k){
				if (Q(x*k+j)&&!vis[x*k+j])
					ans--,vis[x*k+j]=1;
			}
		}
	}
	printf("! %d\n",ans);
	if (type==1){
		cout<<w<<endl;
		cout<<times<<' '<<3*n*n/2/kk<<endl;
	}
	fflush(stdout);
	exit(0);
}
/*

2n^2/k^2

*/