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
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;
    
int main() {
    cin.sync_with_stdio(0);
    int T;
    cin >> T;
    for(int t =0; t < T; t++) {
        long long N;
        cin >> N;
        long long pow[19];
        pow[0] =1;
        for(int i =0; i < 18; i++) pow[i+1] =pow[i]*10;
        vector<bool> pos(47,false); pos[0] =true;
        for(int i =0; i <= 6; i++) for(int j =0; j <= 6-i; j++)
            pos[i*7+j*4] =true;

        map< pair<long long,int>,int> ako;
        ako[make_pair(N,17)] =0;
        auto it =ako.end(); it--;
        while(true) {
            if((it->ff).ff == 0) break;
            if((it->ff).ss < 0) {if(it == ako.begin()) break; it--; continue;}
            long long a =(it->ff).ff; int b =(it->ff).ss;
            for(int i =0; i <= 42; i++) if(pos[i] && i*pow[b] <= a && a-i*pow[b] < pow[b+1])
                ako[make_pair(a-i*pow[b],b-1)] =i;
            if(it == ako.begin()) break;
            it--;}
        if((it->ff).ff > 0) {cout << "-1\n"; continue;}
        
        long long A[6] ={0,0,0,0,0,0};
        long long a =0;
        while(a < N) {
            a +=(it->ss)*pow[(it->ff).ss+1];
            for(int i =0; i <= 6; i++) for(int j =0; j <= 6-i; j++)
                if(7*i+4*j == it->ss) {
                    for(int k =0; k < i; k++) A[k] +=pow[(it->ff).ss+1]*7;
                    for(int k =i; k < i+j; k++) A[k] +=pow[(it->ff).ss+1]*4;
                    break;}
            it =ako.find(make_pair(a,(it->ff).ss+1));}
        for(int i =0; i < 6; i++) {
            if(i > 0) cout << " ";
            cout << A[i];}
        cout << "\n";}
    return 0;}
        
// look at my code
// my code is amazing