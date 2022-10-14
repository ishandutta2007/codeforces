#include <iostream>
#include <algorithm>

using namespace std;

int n,a[1010],b,c,ans[1010],vis[1010],ok = 1;
int main() {
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>b>>c;
		if(max(b,c)!=n)ok = 0;
		a[i] = b;
	}
	sort(a,a+n-1);
	int cp = 0;
	for(int i=0;i<n-1;i++){
		cp = a[i];
		while(vis[cp])cp-=1;
		if(!cp)ok = 0;
		ans[i] = cp;
		vis[cp] = 1;
	}
	ans[n-1] = n;
	if(ok){
		cout<<"YES"<<endl;
		for(int i=0;i<n-1;i++)cout<<ans[i]<<' '<<ans[i+1]<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}