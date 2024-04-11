#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,a[50],cnt;
	cin>>n>>m>>k;
	for(int i=0;i<n;++i) cin>>a[i];
	if(k>=m){
		cout<<0<<endl;
		return 0;}
	sort(a,a+n);
	for(int i=n-1;i>-1;--i){
		k+=a[i]-1;
		cnt++;
		if(k>=m){
			cout<<cnt<<endl;
			return 0;}
	}
	cout<<-1;
}