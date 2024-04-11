#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,M;
long double p,sb,tmp;

int main(){
	cin>>n>>p;
	for(ll i=0;;i++){
		sb=0;
		tmp=i*(n-i)*(n-i-1)/2;
		sb+=tmp/2;
		tmp=i*(i-1)*(n-i)/2;
		sb+=tmp;
		tmp=i*(i-1)*(i-2)/6;
		sb+=tmp;
		sb/=n;sb/=(n-1);sb/=(n-2);sb*=6;
		
		//cout<<i<<' '<<sb<<' '<<p<<endl;
		if(sb>=p-1e-7){
			cout<<i;return 0;
		}
	}
}