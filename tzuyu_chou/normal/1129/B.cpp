#include<iostream>
using namespace std;
int k;
int n=2000;
int p=1e6;
int a[2001];
int main(){
	ios::sync_with_stdio(false);
	cin >> k;
	if(k<=1000000){
		cout << "1\n" << -k << '\n';
		return 0;
	}
	n=k/1000000+150;
	p-=p%n;
	p-=k%n;
	k+=p;
	int sum=0;
	cout << n << endl;
	for(int i=1; i<=n-2 ;i++){
		cout << "-1 ";
		a[i]=-1;
	}
	a[n-1]=k/n-p+n-2;a[n]=p;
	cout << k/n-p+n-2 << ' ';
	cout << p << endl;
	/*int ans=0;
	for(int i=n; i>=1 ;i--){
		sum+=a[i];
		ans=max(ans,(n-i+1)*sum);
		cout << (n-i+1)*sum << endl;
	}
	cout << ans << endl;*/
}