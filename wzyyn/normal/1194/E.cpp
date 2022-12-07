#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long
#define fi first
#define se second
#define uint unsigned
#define PB push_back
using namespace std;
const int N=5005;
int LEN;
int bit[65536];
struct BIT{
	uint a[165]; 
	BIT(){
		memset(a,0,sizeof(a));
	}
	bool set(int x){
		a[x>>5]|=1u<<(x&31);
	}
	BIT operator &(const BIT &b)const{
		BIT ans;
		for (int i=0;i<=LEN;i+=4){
			ans.a[i]=a[i]&b.a[i];
			ans.a[i+1]=a[i+1]&b.a[i+1];
			ans.a[i+2]=a[i+2]&b.a[i+2];
			ans.a[i+3]=a[i+3]&b.a[i+3];
		}
		return ans;
	}
	int count(){
		int ans=0;
		for (int i=0;i<=LEN;i+=4){
			ans+=bit[a[i]&65535]+bit[a[i]>>16];
			ans+=bit[a[i+1]&65535]+bit[a[i+1]>>16];
			ans+=bit[a[i+2]&65535]+bit[a[i+2]>>16];
			ans+=bit[a[i+3]&65535]+bit[a[i+3]>>16];
		}
		return ans;
	}
}B[N];
struct node{
	int x,y,X,Y;
};
vector<node> vec1,vec2;
int n;
ll ans;
int main(){
	For(i,1,65535) bit[i]=bit[i/2]+(i&1);
	scanf("%d",&n);
	For(i,1,n){
		int x,y,X,Y;
		scanf("%d%d%d%d",&x,&y,&X,&Y);
		if (x>X) swap(x,X);
		if (y>Y) swap(y,Y);
		if (x==X) vec1.PB((node){x,y,X,Y}); 
		else vec2.PB((node){x,y,X,Y});
	}
	LEN=(vec2.size()>>5);
	int sz1=vec1.size()-1;
	int sz2=vec2.size()-1;
	For(i,0,sz1) For(j,0,sz2)
		if (vec2[j].x<=vec1[i].x&&vec1[i].x<=vec2[j].X)
			if (vec1[i].y<=vec2[j].y&&vec2[j].y<=vec1[i].Y)
				B[i].set(j);
	For(i,0,sz1) For(j,i+1,sz1){
		int cnt=(B[i]&B[j]).count();
		ans+=cnt*(cnt-1)/2;
	} 
	printf("%lld\n",ans);
}