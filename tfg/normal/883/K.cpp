#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define X first
#define Y second
using namespace std;

const int ms=1e6+10;

int lw[ms],rd[ms],bl[ms],n;

int main() {
	cin>>n;
	fr(i,0,n){
		cin>>rd[i]>>lw[i];
		if(i)bl[i]=min(bl[i-1]+1,lw[i]+rd[i]);
		else bl[i]=lw[i]+rd[i];
	}
	for(int i=n-2;i>=0;i--){
		bl[i]=min(bl[i+1]+1,bl[i]);
	}
	long long int ans=0;
	fr(i,0,n){
		ans+=bl[i]-rd[i];
		if(bl[i]<rd[i]){
			puts("-1");
			return 0;//fsdfdsfjgbsdfjbgjdfsbjk
		}
	}
	cout<<ans<<endl;
	fr(i,0,n)cout<<bl[i]<<" ";
	puts("");
}