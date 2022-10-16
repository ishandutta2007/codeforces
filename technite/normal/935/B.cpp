#include<iostream>
using namespace std;
int main(){
    int n, a=0, b=0, c=0;
    string s;

	cin >> n >> s;
	for( int i = 0; i < n; i ++ ){
		if( s[ i ] == 'U' ) a ++;
		else b ++;
		if( s[ i ] == s[ i + 1 ] && b == a ) c++;
	}
	cout << c;
}