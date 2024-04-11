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

int n,Q,t[1<<20];
void change(int x,int v){
	for (;x<1<<20;x+=x&(-x)) t[x]+=v;
}
int find(int v){
	int p=0;
	Rep(i,19,0)
		if (t[p+(1<<i)]<v)
			p+=1<<i,v-=t[p];
	//cout<<p<<' '<<v<<endl;
	return p+1;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n+Q){
		int x;
		scanf("%d",&x);
		if (x>0) change(x,1);
		else change(find(-x),-1);
	}
	For(i,1,n) if (t[i])
		return printf("%d\n",i),0;
	printf("0");
}