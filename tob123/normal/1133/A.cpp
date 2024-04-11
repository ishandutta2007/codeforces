#include <bits/stdc++.h>
using namespace std;

int main(){
    int b = 0, d = 0;
    
    char c1, c2;
    cin >> c1 >> c2;
    b = 60*((c1-'0')*10 + (c2-'0'+0));
    cin >> c1;
    cin >> c1 >> c2;
    b += 1*((c1-'0')*10 + (c2-'0'));
    
    cin >> c1 >> c2;
    d = 60*((c1-'0')*10 + (c2-'0'));
    cin >> c1;
    cin >> c1 >> c2;
    d += 1*((c1-'0')*10 + (c2-'0'));
    
	int m = (b+d)/2;
	int r1 = m/60;
	int r2 = m%60;
	if(r1 < 10)
	    cout <<"0";
	cout << r1 << ":";
	if(r2 < 10)
	    cout <<"0";
	cout << r2 << endl;
}