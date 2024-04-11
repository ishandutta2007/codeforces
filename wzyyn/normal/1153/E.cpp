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
int n,v;

int F1(int x1){
	int l=1,r=n-1,p=n;
	while (l<=r){
		int mid=(l+r)/2;
		cout<<"? "<<x1<<' '<<1<<' '<<x1<<' '<<mid<<endl;
		cin>>v;
		if (v&1) p=mid,r=mid-1;
		else l=mid+1;
	}
	return p;
}
int F2(int y1){
	int l=1,r=n-1,p=n;
	while (l<=r){
		int mid=(l+r)/2;
		cout<<"? "<<1<<' '<<y1<<' '<<mid<<' '<<y1<<endl;
		cin>>v;
		if (v&1) p=mid,r=mid-1;
		else l=mid+1;
	}
	return p;
}
int main(){
	scanf("%d",&n);
	int x1=n+1,x2=0;
	int y1=n+1,y2=0;
	for (int i=1;i<n;i++){
		cout<<"? "<<1<<' '<<1<<' '<<i<<' '<<n<<endl;
		cin>>v;
		if (v&1) x1=min(x1,i),x2=max(x2,i+1);
	}
	for (int i=1;i<n;i++){
		cout<<"? "<<1<<' '<<1<<' '<<n<<' '<<i<<endl;
		cin>>v;
		if (v&1) y1=min(y1,i),y2=max(y2,i+1);
	}
	if (x2){
		int p1=F1(x1),p2=F1(x2);
		cout<<"! "<<x1<<' '<<p1<<' '<<x2<<' '<<p2<<endl;
	}
	else{
		int p1=F2(y1),p2=F2(y2);
		cout<<"! "<<p1<<' '<<y1<<' '<<p2<<' '<<y2<<endl;
	}
}