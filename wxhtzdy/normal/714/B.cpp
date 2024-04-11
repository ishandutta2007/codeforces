#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	map<int,int> was;
	map<int,int> wasdiff;
	int cnt=0,diff=0;
	for(int i=0;i<n;i++){
		if(!was[a[i]])cnt++;
		was[a[i]]=1;
		if(i>0){
			if(!wasdiff[abs(a[i]-a[i-1])]&&a[i]!=a[i-1])diff++;
			wasdiff[abs(a[i]-a[i-1])]=1;
		}
	}
	if(cnt<3||(cnt==3&&diff<=1))cout<<"YES";
	else cout<<"NO";
	return 0;	
}