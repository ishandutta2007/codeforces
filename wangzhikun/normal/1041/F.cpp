#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> a;
unordered_map<int, int>::iterator it;

int n,nu,ans = 0;

int main() {
	cin>>n>>nu;
	for(int i=0;i<n;i++){
		cin>>nu;
		for(int i=1;i<30;i++)a[nu%(1<<i)+(1<<i)]+=1;
		a[nu+(1<<30)]+=1;
	}
	cin>>n>>nu;
	for(int i=0;i<n;i++){
		cin>>nu;
		for(int i=1;i<30;i++)a[(nu+(1<<(i-1)))%(1<<i)+(1<<i)]+=1;
		a[nu+(1<<30)]+=1;
	}
	it = a.begin();
	pair<int,int> c;
	while(it!=a.end()){
		c = *it;
		ans = max(ans,c.second);
		
		it++;
	}
	cout<<ans<<endl;
	return 0;
}