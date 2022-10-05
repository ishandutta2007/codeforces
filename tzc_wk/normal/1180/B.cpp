#include <bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>=0)	b[i]=-a[i]-1;
		else		b[i]=a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]<0)
			cnt++;
	}
	if(cnt%2){
		int ind=0,mx=0;
		for(int i=1;i<=n;i++){
			if(abs(b[i])>mx)	mx=abs(b[i]),ind=i;
		}
		b[ind]=-b[ind]-1;
	}
	for(int i=1;i<=n;i++)	cout<<b[i]<<" ";
	return 0;
}