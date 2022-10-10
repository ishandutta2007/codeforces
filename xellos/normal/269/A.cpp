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
#define chocolate win
// mylittlepony
using namespace std;
	
int main() {
    int N,a,b, ans =0;
    cin >> N;
    int pow[16];
    pow[0] =1;
    for(int i =1; i <= 15; i++) pow[i] =pow[i-1]*4;
    
    for(int i =0; i < N; i++) {
        cin >> a >> b;
        for(int j =0; j <= 15; j++) if(pow[j] >= b) {
            if(b == 1) ans =max(ans,a+j+1);
            else ans =max(ans,a+j);
            break;}
        }
    cout << ans << endl;
    return 0;}
        
// look at my code
// my code is amazing