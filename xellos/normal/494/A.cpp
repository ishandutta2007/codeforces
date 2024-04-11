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
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string V;
    cin >> V;
    int N =V.length();
    int d =0, s =0;
    bool ok =true;
   	int x =-1;
    for(int i =0; i < N; i++) if(V[i] == '#') x =i;
    int p =0;
    for(int i =0; i < N; i++) if(i != x && V[i] == '#') {V[i] =')'; p++;}
    for(int i =0; i < N; i++) {
    	if(V[i] == '(') s++;
    	if(V[i] == ')') s--;}
    if(s <= 0 && x != -1) {cout << "-1\n"; return 0;}
    for(int i =0; i < N; i++) {
    	if(V[i] == '#') d -=s;
    	else if(V[i] == '(') d++;
    	else d--;
    	if(d < 0) ok =false;}
    if(d != 0 || !ok) cout << "-1\n";
    else {
    	for(int i =0; i < p; i++) cout << "1\n";
    	if(x != -1) cout << s << "\n";}
    return 0;}
        
// look at my code
// my code is amazing