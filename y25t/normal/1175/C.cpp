#include<iostream>
using namespace std;
#define N 200005

int T;

int n,k,a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		int ans=k+1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>k&&a[i]-a[i-k]<a[ans]-a[ans-k])
				ans=i;
		}
		cout<<(a[ans]+a[ans-k])/2<<'\n';
	}
}