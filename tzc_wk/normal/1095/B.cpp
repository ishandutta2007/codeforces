#include <bits/stdc++.h>
using namespace std;
int a[100100],n;
void Sort(){
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		pq.push(a[i]);
	}
	for(int i=n-1;i>=0;i--){
		a[i]=pq.top();
		pq.pop();
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	Sort();
	int ans1=a[n-1]-a[1],ans2=a[n-2]-a[0];
	cout<<min(ans1,ans2)<<endl;
}//