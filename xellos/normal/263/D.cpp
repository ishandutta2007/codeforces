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
    int N,M,K,a,b;
    scanf(" %d %d %d",&N,&M,&K);
    vector< vector<int> > V(N);
    for(int i =0; i < M; i++) {
        scanf(" %d %d",&a,&b);
        a--,b--;
        V[a].push_back(b);
        V[b].push_back(a);}
    
    vector<int> S(1,0);
    vector<bool> isS(N,false);
    isS[0] =true;
    for(int i =0; i < K; i++) {
        a =*S.rbegin();
        ALL_THE(V[a],it) if(!isS[*it]) {
            isS[*it] =true;
            S.push_back(*it);
            break;}}

    b =-1;
    vector<bool> isSk(N,false);
    isSk[0] =true;
    for(int i =K; i < N; i++) {
        a =*S.rbegin();
        ALL_THE(V[a],it) if(isSk[*it]) {
            b =*it;
            break;}
        if(b != -1) break;
        ALL_THE(V[a],it) if(!isS[*it]) {
            isS[*it] =true;
            isSk[*(S.end()-K)] =true;
            S.push_back(*it);
            break;}}
    
    vector<int> W(1,b);
    while(*S.rbegin() != b) {
        W.push_back(*S.rbegin());
        S.pop_back();}
    printf("%d\n",W.size());
    ALL_THE(W,it) {
        if(it != W.begin()) printf(" ");
        printf("%d",*it+1);}
    printf("\n");
    return 0;}
        
// look at my code
// my code is amazing