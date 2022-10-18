#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x = 1;
    for (int i = 1; i < n; i++){
    	x = (x + i) % n;
    	if (x == 0){
    		x = n;
		}
		cout << x << " ";
	}
}