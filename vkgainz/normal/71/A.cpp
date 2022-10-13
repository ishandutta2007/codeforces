#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <cctype> 
#include <string> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <functional>
#include <string>
using namespace std;
 
 
int main() {
 
    int N;
    cin >> N;
    string x[N];
    for(int i = 0; i < N; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < N; i++) {
        int len = size(x[i]);
        if(len > 10){
        string a = to_string(len - 2);
        x[i] = x[i][0] + a + x[i][len - 1];
        }
    }
    for(int i = 0; i < N; i++) {
      cout << x[i]<< endl;
    }
 
    
}