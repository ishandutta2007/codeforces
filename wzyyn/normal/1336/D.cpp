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
const int N=105;
int n,nd,mat[N*N];
int a[N],b[N],val[N];
void getinfo(int id){
	scanf("%d%d",&a[id],&b[id]);
}
void ext(int x){
	cout<<"+ "<<x<<endl;
	getinfo(++nd);
}
int main(){
	scanf("%d",&n);
	For(i,2,n+1) mat[i*(i-1)/2]=i;
	For(i,1,n) val[i]=-1;
	getinfo(nd=0);
	For(i,1,n-1) ext(i); ext(1);
	Rep(i,nd,1) a[i]-=a[i-1],b[i]-=b[i-1];
	For(i,1,n-1) if (a[i]) val[i]=mat[a[i]];
	if (val[1]==-1) val[1]=(a[n]?1:0);
	int sum23=b[n]-b[1]-1;
	if (val[2]!=-1) val[3]=sum23-val[2];
	if (val[3]!=-1) val[2]=sum23-val[3];
	if (val[2]==-1||val[3]==-1)
		if (sum23%2==0) val[2]=val[3]=sum23/2;
		else val[2]=(b[2]==0),val[3]=(b[2]!=0);
	For(i,4,n-1) if (val[i]==-1)
		val[i]=(b[i-1]!=(val[i-3]+1)*(val[i-2]+1));
	val[n]=b[n-1]/(val[n-2]+1)-(val[n-3]+1);
	printf("! ");
	For(i,1,n) printf("%d ",val[i]);
}