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
int n,p,x;
int main(){
	cin>>n;
	cout<<"? 1 "<<n<<endl;
	cin>>p;
	int l=1,r=n-1;
	while (l<r){
		int mid=(l+r)/2;
		cout<<"? "<<max(1,p-mid)<<' '<<min(n,p+mid)<<endl;
		cin>>x;
		if (x==p) r=mid;
		else l=mid+1;
	}
	if (p==1) cout<<"! "<<p+r<<endl;
	else{
		cout<<"? "<<max(1,p-r)<<' '<<p<<endl;
		cin>>x;
		cout<<"! "<<(x==p?p-r:p+r)<<endl;
	}
}