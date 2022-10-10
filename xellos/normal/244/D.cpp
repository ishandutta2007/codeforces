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
    int N,M,H,T,a,b;
    scanf(" %d %d %d %d",&N,&M,&H,&T);
    int x =min(H,T);
    vector< vector<int> > adjL(N);
    for(int i =0; i < M; i++) {
        scanf(" %d %d",&a,&b);
        adjL[--a].push_back(--b);
        adjL[b].push_back(a);}

    vector<bool> X(N,false);
    a =b =-1;
    for(int i =0; i < N; i++) if(adjL[i].size() > x && a == -1) {
        ALL_THE(adjL[i],it) X[*it] =true;
        ALL_THE(adjL[i],it) {
            if(adjL[*it].size() <= x) continue;
            if(max(adjL[i].size(),adjL[*it].size()) <= max(H,T)) continue;
            if(adjL[*it].size() > H+T || adjL[i].size() > H+T) {
                a =i, b =*it;
                break;}
            int c =0; // common neighbors
            ALL_THE(adjL[*it],jt) if(X[*jt]) c++;
            if(adjL[i].size()+adjL[*it].size()-c-2 < H+T) continue;
            a =i, b =*it;
            break;}
        ALL_THE(adjL[i],it) X[*it] =false;}
    
    if(a == -1) {
        cout << "NO\n";
        return 0;}
    cout << "YES\n";
    if((adjL[a].size() < adjL[b].size())^(H < T)) swap(a,b);
    cout << a+1 << " " << b+1 << "\n";
    ALL_THE(adjL[a],it) X[*it] =true;
    vector<int> C;
    ALL_THE(adjL[b],it) {
        if(X[*it]) C.push_back(*it);
        X[*it] =false;}
    X[b] =false;
    bool zac =false;
    for(int i =0; i < N; i++) if(X[i]) {
        if(zac) cout << " ";
        else zac =true;
        cout << i+1;
        H--;
        if(H == 0) break;}
    for(int i =0; i < N; i++) X[i] =false;
    ALL_THE(adjL[b],it) X[*it] =true;
    X[a] =false;
    ALL_THE(adjL[a],it) X[*it] =false;
    for(int i =0; i < H; i++) {
        if(zac) cout << " ";
        else zac =true;
        cout << C[i]+1;}
    cout << "\n";
    zac =false;
    for(int i =0; i < N; i++) if(X[i]) {
        if(zac) cout << " ";
        else zac =true;
        cout << i+1;
        T--;
        if(T == 0) break;}
    for(int i =H; i < min(H+T,(int)C.size()); i++) {
        if(zac) cout << " ";
        else zac =true;
        cout << C[i]+1;}
    cout << endl;
    return 0;}
        
// look at my code
// my code is amazing