// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
// mylittlepony
using namespace std;
	
int main() {
    int N,T;
    string s;
    cin >> N >> T >> s;
    for(int i =0; i < T; i++) {
        string t =s;
        for(int j =1; j < s.length(); j++) if(s[j] == 'G' && s[j-1] == 'B') swap(t[j],t[j-1]);
        s =t;}
    cout << s << endl;
    return 0;}
        
// look at my code
// my code is amazing