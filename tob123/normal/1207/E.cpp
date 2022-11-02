#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
	int a, b;
	cout << "?";
	for(int i=0; i<100; i++){
		cout << " " << i;
	}
	cout << endl;
	cin >> a;
	cout << "?";
	for(int i=0; i<100; i++){
		cout << " " << ((i+1)*(1<<7));
	}
	cout << endl;
	cin >> b;
	/*
	for(int i=0; i<(1<<14); i++){
	int val = i;
	a = val ^ 7;
	b = val ^ (38*(1<<7));
	//cout << a << endl;
	//cout << b << endl;
	*/
	b &= (1<<7)-1;
	a &= ~((1<<7)-1);
	/*
	if(a+b != val)
		cout << i << endl;
		*/
	cout << "! " << a+b << endl;

  return 0;
}