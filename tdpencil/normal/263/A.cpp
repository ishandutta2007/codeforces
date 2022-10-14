#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll ans=0;
	int matrix[5][5];
	for(int i=0; i < 5; i++){
		for(int j =0; j < 5; j++){
			cin >> matrix[i][j];
			if(matrix[i][j])
				ans=abs(i-2)+abs(j-2);
		}
	}
	cout << ans;
	
}