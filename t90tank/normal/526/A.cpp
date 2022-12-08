#include <bits/stdc++.h>
using namespace std; 

string S; 
int n; 
int a[3000]; 

int main() {
	cin>>n; 
	cin>>S; 
	bool flag = false; 
	for (int i = 1; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			if ( S[j] == '.' ) a[j] = 0; 
			else {
				if ( j < i ) a[j] = 1; 
				else a[j] = a[j-i] + 1; 
				//cout<<a[j]<<endl; 
				if ( a[j] >= 5 ) {
					flag = true; 
					break;
				}
			}
	if ( flag ) cout<<"yes\n"; 
	else cout<<"no\n";  
}