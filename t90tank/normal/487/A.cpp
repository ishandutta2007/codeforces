#include <bits/stdc++.h>
using namespace std; 

int hp1, atk1, def1, hp2, atk2, def2; 
int h, a, d; 
int ans; 

void cmp(int a, int b, int c, int d, int cost) {
	if ( b > 0 ) {
		if ( d <= 0 ) ans = min( ans, cost ); 
		else ans = min( ans, max(0,((a-1)/b+1)*d-c+1)*h+cost ); 
	}
}

int main() {
	cin>>hp1>>atk1>>def1>>hp2>>atk2>>def2>>h>>a>>d;
	ans=200*(h+a+d);  
	for (int j = 0; j <= 200; ++j) 
		for (int k = 0; k <= 200; ++k) 
			cmp(hp2, atk1+j-def2, hp1, atk2-def1-k, j*a+k*d); 
	cout<<ans<<endl; 
}