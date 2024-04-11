#include<bits/stdc++.h>
using namespace std;

int main(){
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    int pos = v0, t = 1, add = v0;
	while (pos < c){
		add = min(v1, add + a);
		pos += add - l;
		t++;
	}
	cout << t;
}