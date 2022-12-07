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

#define info pair<bool,unsigned short>
int q[32],qq[32],pos[32],n,p;
bool f[32][32][50005];
info fr[32][32][50005];
int main(){
	scanf("%d%d",&n,&p);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		if (x<=31){
			q[++*q]=x;
			pos[*q]=i;
		}
	}
	//f[0][0][0]=1;
	For(i,1,*q){
		f[i][q[i]][q[i]%p]=1;
		fr[i][q[i]][q[i]%p]=info(1,p+1);
		For(j,0,31) For(k,0,p-1)
			if (f[i-1][j][k]){
				f[i][j][k]=1;
				fr[i][j][k]=info(0,0);
				int nv=(k*(q[i]<=9?10:100)+q[i])%p;
				f[i][j^q[i]][nv]=1;
				fr[i][j^q[i]][nv]=info(1,k);
			}
	}
	if (!f[*q][0][0])
		return puts("No"),0;
	puts("Yes");
	int px=0,py=0;
	Rep(i,*q,1){
		//cout<<px<<' '<<py<<endl;
		if (py<0||py>=p) break;
		if (fr[i][px][py].fi==0) continue;
		int v1=fr[i][px][py].se;
		px^=q[i]; py=v1;
		qq[++*qq]=pos[i];
	} 
	reverse(qq+1,qq+*qq+1);
	printf("%d\n",*qq);
	For(i,1,*qq) printf("%d ",qq[i]);
}