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

const int N=200005;
int n,k,a[N],s[N];
bool check(int v){
	For(i,1,n) s[i]=s[i-1]+(a[i]>=v?1:-1);
	int mn=0;
	For(i,k,n){
		mn=min(mn,s[i-k]);
		if (s[i]>mn) return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	int l=1,r=n,re=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)) re=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<re<<endl;
}