#include<bits/stdc++.h>
using namespace std;

int main(){
	char n = 'a', t;
	int s = 0;
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++){
		t = a[i];
		int dis = abs(n - t);
		if (dis < 26 - dis){
			s += dis;
		}
		else{
			s += 26 - dis;
		}
		n = t; 
	}
	cout << s;
}