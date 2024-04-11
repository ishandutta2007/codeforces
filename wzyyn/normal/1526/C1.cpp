#include<bits/stdc++.h>
using namespace std;

priority_queue<int> Q;
int n,ans;
long long s;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (x>=0){
			++ans;
			s+=x;
		}
		else{
			++ans;
			s+=x;
			Q.push(-x);
			while (s<0){
				int y=Q.top();
				Q.pop();
				s+=y;
				ans--;
			}
		}
	}
	cout<<ans<<endl;
}