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
    int N;
    scanf(" %d",&N);
    vector<int> A(N);
    ALL_THE(A,it) scanf(" %d",&(*it));
    
    vector< queue<int> > div(100000);
    vector< vector<int> > p(N);
    
    vector<bool> isP(100000+tisic,true);
    vector<int> P;
    for(int i =2; i <= 100000; i++) if(isP[i]) {
        P.push_back(i);
        for(int j =i; j <= 100000/i; j++) isP[i*j] =false;}
        
    for(int i =0; i < N; i++) {
        int x =A[i];
        ALL_THE(P,it) {
            if((*it)*(*it) > x) break;
            if(x%(*it) == 0) {
                while(x%(*it) == 0) x /=*it;
                div[*it].push(i);
                p[i].push_back(*it);}
            }
        if(x > 1) {
            div[x].push(i);
            p[i].push_back(x);}}
    for(int i =0; i < 100000; i++) div[i].push(N);
    
    vector<int> ans(N,1);
    for(int i =0; i < N-1; i++) {
        ALL_THE(p[i],it) {
            while(div[*it].front() <= i) div[*it].pop();
            if(div[*it].front() < N) ans[div[*it].front()] =max(ans[div[*it].front()],ans[i]+1);}
        }
    int ansR =0;
    ALL_THE(ans,it) ansR =max(ansR,*it);
    printf("%d\n",ansR);
    return 0;}
        
// look at my code
// my code is amazing