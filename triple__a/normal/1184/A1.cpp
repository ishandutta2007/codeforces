#include<bits/stdc++.h>
using namespace std;
 
const int maxn=100007;
typedef long long ll;
 
ll r;
 
int main(){
	cin>>r;
	if (r%2&&r>3){
		cout<<1<<" "<<(r-3)/2;
	}
	else{
		printf("NO");
	}
	return 0;
}