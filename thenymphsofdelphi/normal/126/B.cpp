#include<iostream>
#include<string.h>
using namespace std;
 
int main(){
    string s;
    cin >> s;
    int n = s.length();
    int L = 0, R = 0;
    int z[n];
    for (int i = 0; i < n; i++){
    	z[i] = 0;
	}
	for (int i = 1; i < n; i++){
		if (i > R){
			L = R = i;
			while (R < n && s[R - L] == s[R]){
				R++;
			}
			z[i] = R - L;
			R--;
		}
		else{
			int k = i - L;
			if (z[k] < R - i + 1){
				z[i] = z[k];
			}
			else{
				L = i;
				while (R < n && s[R-L] == s[R]){
					R++;
				}
				z[i] = R - L;
				R--;
			}
		}
	}
	int maxz = 0, res = 0;
	for (int i = 1; i < n; i++){
		if (z[i] == n - i && maxz >= n - i){
			res = n - i; 
			break; 
		}
		maxz = max(maxz, z[i]);
	}
	if (res == 0){
		cout << "Just a legend";
	}
	else{
		cout << s.substr(0, res);
	}
}