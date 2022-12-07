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
int vis[N];
int n,k,ans;
int Q(int x){
	printf("? %d\n",x);
	fflush(stdout);
	char s[5];
	scanf("%s",s+1);
	return s[1]=='Y';
}
int main(){
	scanf("%d%d",&n,&k);
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
		int blk=n/k;
		For(i,1,blk) For(j,0,i-1){
			if (j+i>=blk) continue;
			if (type==0){
				printf("R\n");
				fflush(stdout);
			}
			int x=j;
			for (;x<blk;x+=i) For(j,1,k){
				if (Q(x*k+j)&&!vis[x*k+j])
					ans--,vis[x*k+j]=1;
			}
		}
	}
	printf("! %d\n",ans);
	fflush(stdout);
	exit(0);
}
/*
 
2n^2/k^2
 
*/