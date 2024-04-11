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
const int B=1<<8,N=(1<<12)|5;
int t[B*2][B|5][B|5];
int tt[20][B|5][B|5];
int n,Q,a[N],pos[N],ans[N*B];
int ansL[1<<22],ansR[1<<22],nd;
int p1[N],p2[N],q[N],p[20][N];
int ADD(int x,int y){
	if (!x||!y) return x+y;
	ansL[++nd]=x; ansR[nd]=y; return nd; 
}
void output(){
	printf("%d\n",nd);
	For(i,n+1,nd) printf("%d %d\n",ansL[i],ansR[i]);
}
void init(int k,int L,int R){
	if (L==R){
		t[k][1][1]=pos[L];
		return;
	}
	int mid=(L+R)/2;
	init(k*2,L,mid);
	init(k*2+1,mid+1,R);
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	For(i,L,mid) p1[pos[i]]++;
	For(i,mid+1,R) p2[pos[i]]++;
	For(i,1,n){
		p1[i]+=p1[i-1];
		p2[i]+=p2[i-1];
	}
	*q=0;
	For(i,L,R) q[++*q]=pos[i];
	sort(q+1,q+*q+1);
	For(i,1,*q) For(j,i,*q){
		int pl1=p1[q[i]-1]+1,pr1=p1[q[j]];
		int pl2=p2[q[i]-1]+1,pr2=p2[q[j]];
		int v1=(pl1<=pr1?t[k*2][pl1][pr1]:0);
		int v2=(pl2<=pr2?t[k*2+1][pl2][pr2]:0);
		t[k][i][j]=ADD(v1,v2);
	}
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]),pos[a[i]]=i;
	int cnt=(n-1)/B+1; nd=n;
	For(i,1,cnt){
		int L=(i-1)*B+1,R=min(n,i*B);
		For(j,L,R) p[i][pos[j]]=1;
		For(j,1,n) p[i][j]+=p[i][j-1];
		init(1,L,R);
		int sum=R-L+1;
		For(j,1,sum) For(k,j,sum)
			tt[i][j][k]=t[1][j][k];
	}
	For(i,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		ans[i]=0;
		For(j,1,cnt){
			int pl=p[j][l-1]+1;
			int pr=p[j][r];
			//cout<<pl<<' '<<pr<<endl;
			ans[i]=ADD(ans[i],tt[j][pl][pr]);
		}
	}
	output();
	For(i,1,Q) printf("%d ",ans[i]);
}
/*
 
*/