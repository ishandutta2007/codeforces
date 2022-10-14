#include<bits/stdc++.h>
using namespace std;
int main(){
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		int a[2*n];
		for(int i=0;i<2*n;i++)cin>>a[i];
		map<int,int> cnt;
		int b[n],sz=0;
		for(int i=0;i<2*n;i++){
			if(cnt[a[i]]==0)b[sz]=a[i],sz++;
			cnt[a[i]]++;
		}
		for(int i=0;i<n;i++)cout<<b[i]<<" ";
		cout<<endl;
	}
}