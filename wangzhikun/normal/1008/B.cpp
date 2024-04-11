// Author : WangZhikun
// Date   : 2018.07.26

#include <iostream>

using namespace std;
typedef long long ll;

int n,cm = 1e9+7,a[100010],b[100010];
int main() {
	cin>>n;
	int ans = 1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		if(max(a[i],b[i])<=cm){
			cm = max(a[i],b[i]);
		}else if(min(a[i],b[i])<=cm){
			cm = min(a[i],b[i]);
		}else{
			ans = 0;
		}
	}
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}