#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<map>
#include<utility>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
typedef long long int lint;
typedef long double ldb;

const lint INF = 1e16;

int main() {
    string a, b;
    ios_base::sync_with_stdio(false);
    getline(cin, a);
    getline(cin, b);
    int b1 = 0, b2 = 0;
    while(b1 < a.length() && a[b1] == '0')
        b1++;
    if(b1 == a.length()){a = "0";}else{a = a.substr(b1);}
    while(b2 < b.length() && b[b2] == '0')
        b2++;
    if(b2 == b.length()){b = "0";}else{b = b.substr(b2);}
    if(a.length() < b.length()){cout << "<" << endl; return 0;}
    if(a.length() > b.length()){cout << ">" << endl; return 0;}
    for(int i = 0; i < a.length(); i++){
        if(a[i] < b[i]){cout << "<" << endl; return 0;}
        if(a[i] > b[i]){cout << ">" << endl; return 0;}
    }
    cout << "=" << endl;
	return 0;
}