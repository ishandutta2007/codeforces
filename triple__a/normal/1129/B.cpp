#include<bits/stdc++.h>
using namespace std;

const int maxn=2007;
const int t=1e6;
int ans[maxn],k,n=2000,x;

int main(){
	cin>>k;
	if (k<=t-2){
		cout<<2<<endl;
		cout<<-1<<" "<<k+2<<endl;
		return 0;
	}
	n=1999;
	x=(k+t)%n;
	cout<<n<<endl;
	int sum=(k+t-x)/n;
	for (int i=1;i<999;++i){
		cout<<1<<" "<<-2<<" ";
	}	
	cout<<1<<" "<<-(t-x-998-sum)-1<<" ";
	cout<<t-x<<endl;
}