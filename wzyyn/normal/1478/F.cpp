#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=5005;
int n,id[N];
struct P{
	int x,y;
}p[N];
bool check(int j){
	if (j<2) return 0;
	return 1ll*(p[j-1].x-p[j].x)*(p[j-1].x-p[j-2].x)+
		   1ll*(p[j-1].y-p[j].y)*(p[j-1].y-p[j-2].y)<=0;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&p[i].x,&p[i].y);
	For(i,1,n){
		id[i]=i;
		for (int j=i;check(j);--j)
			swap(p[j],p[j-1]),swap(id[j],id[j-1]);
	}
	For(i,1,n) printf("%d ",id[i]);
}