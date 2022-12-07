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
vector<int> v[2]; 
bool isprime(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return 0;
	return 1;
}
void mian(){
	int n;
	cin>>n;
	if (n==1) cout<<"FastestFinger\n";
	else if (n==2) cout<<"Ashishgup\n";
	else if (n&1) cout<<"Ashishgup\n";
	else if (n&2) cout<<(isprime(n/2)?"FastestFinger\n":"Ashishgup\n");
	else if ((n&(-n))!=n) cout<<"Ashishgup\n";
	else cout<<"FastestFinger\n";
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) mian();
}