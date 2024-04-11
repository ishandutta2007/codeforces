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
    string s;
    cin >> s;
    int N =s.length();
    stack<int> L,R;
    for(int i =0; i < N; i++) {
        if(s[i] == 'r') L.push(i);
        else R.push(i);}
    stack<int> S;
    while(!L.empty()) {
        S.push(L.top());
        L.pop();}
    while(!S.empty()) {
        printf("%d\n",S.top()+1);
        S.pop();}
    while(!R.empty()) {
        printf("%d\n",R.top()+1);
        R.pop();}
    
    return 0;}
        
// look at my code
// my code is amazing