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
int w,n,Q,x,P[15];
int a[5000],b[550000];
char s[15];
void insert(int d,int x,int y){
	//cout<<d<<' '<<x<<' '<<y<<endl;
	if (d==w) return b[y]+=a[x],void(0);
	insert(d+1,x,y+2*P[d]);
	insert(d+1,x,y+((x>>d)&1)*P[d]);
}
int query(int d,int x,int y){
	if (d==w) return b[x]*b[y];
	if (s[d]=='X') return query(d+1,x,y)+query(d+1,x+P[d],y+P[d]);
	if (s[d]=='x') return query(d+1,x,y+P[d])+query(d+1,x+P[d],y);
	if (s[d]=='A') return query(d+1,x+2*P[d],y+2*P[d])-query(d+1,x+P[d],y+P[d]);
	if (s[d]=='a') return query(d+1,x+P[d],y+P[d]);
	if (s[d]=='O') return query(d+1,x,y);
	if (s[d]=='o') return query(d+1,x+2*P[d],y+2*P[d])-query(d+1,x,y);
}
int main(){
	P[0]=1;
	For(i,1,12) P[i]=P[i-1]*3;
	scanf("%d%d%d",&w,&n,&Q);
	For(i,1,n) scanf("%d",&x),++a[x];
	For(i,0,(1<<w)-1) insert(0,i,0);
	while (Q--){
		scanf("%s",s);
		reverse(s,s+w);
		printf("%d\n",query(0,0,0));
	}
}