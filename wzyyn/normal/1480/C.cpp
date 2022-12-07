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

int n;
int query(int x){
	if (x<1||x>n) return 1e9;
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}
int main(){
	scanf("%d",&n);
	int l=1,r=n;
	while (l<=r){
		int mid=(l+r)/2;
		int v1=query(mid-1);
		int v2=query(mid);
		int v3=query(mid+1);
		if (v2<v1&&v2<v3){
			cout<<"! "<<mid<<endl;
			exit(0);
		}
		if (v1<v2) r=mid-1;
		else l=mid+1;
	}
}