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
const int N=200005;
int n,Q,a[N],vi[N];
ll S[N];
void Query(ll rank){
	int l=max(1,n-14),r=n;
	For(i,l,r) vi[i]=0;
	ll way=1;
	For(i,1,r-l+1) way*=i;
	For(i,l,r){
		way/=(r-i+1);
		int rk=rank/way;
		rank%=way;
		For(j,l,r)
			if (!vi[j])
				if (!(rk--)){
					a[i]=j;
					break;
				}
		vi[a[i]]=1;
		S[i]=S[i-1]+a[i];
	}
	//int l,r;
	scanf("%d%d",&l,&r);
	cout<<S[r]-S[l-1]<<endl; 
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) a[i]=i,S[i]=S[i-1]+i;
	long long rank=0;
	while (Q--){
		int tp;
		scanf("%d",&tp);
		if (tp==1) Query(rank);
		else{
			int x;
			scanf("%d",&x);
			rank+=x;
		}
	}
}