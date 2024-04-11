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

int ans(int x) {if(x<0) return -x; else return x;}

int main() {
    int N,a,b;
    scanf(" %d",&N);
    
    vector< vector<int> > con(N);
    for(int i =0; i < 2*N; i++) {
        scanf(" %d %d",&a,&b);
        a--, b--;
        con[a].push_back(b);
        con[b].push_back(a);}
    for(int i =0; i < N; i++) if(con[i].size() != 4) {
        printf("-1\n");
        return 0;}
    
    if(N == 5) {
        printf("1 2 3 4 5\n");
        return 0;}
    if(N == 6) {
        //TODO
        vector<int> V(N);
        for(int i =0; i < N; i++) V[i] =i;
        while(true) {
            int ok =0;
            for(unsigned int i =0; i < 6; i++) for(int j =0; j < 4; j++) {
                if(con[V[i]][j] == V[(i+1)%6]) ok++;
                else if(con[V[i]][j] == V[(i+5)%6]) ok++;
                else if(con[V[i]][j] == V[(i+2)%6]) ok++;
                else if(con[V[i]][j] == V[(i+4)%6]) ok++;
                else break;}
            if(ok == 24) {
                for(int i =0; i < N; i++) {
                    if(i > 0) printf(" ");
                    printf("%d",V[i]+1);}
                printf("\n");
                return 0;}
            if(!next_permutation(V.begin(),V.end())) break;}
        printf("-1\n");
        return 0;}
    
    vector<int> V(N,0);
    a =-1;
    b =0;
    int c =-1;
    // choose first 2 neigh.
    for(int i =0; i < 4; i++) {
        int x =0;
        // connections of con[0][i] to con[0][j]
        for(int j =0; j < 4; j++) for(int k =0; k < 4; k++) 
            if(con[0][j] != con[0][i]) if(con[con[0][i]][k] == con[0][j]) x++;
        if(x == 2) {
            if(a == -1) a =con[0][i];
            else c =con[0][i];}}
    V[0] =a, V[1] =b, V[2] =c;
    if(a == -1 || c == -1) {
        printf("-1\n");
        return 0;}
    
    for(int i =3; i < N; i++) {
        // connected to b,c, other than a
        bool B =true;
        for(int j =0; j < 4; j++) if(con[c][j] != a && B) for(int k =0; k < 4; k++) 
            if(con[c][j] == con[b][k]) {
                a =b;
                b =c;
                c =con[c][j];
                B =false;
                break;}
        V[i] =c;}
    vector<int> W =V;
    sort(W.begin(),W.end());
    for(int i =0; i < N; i++) if(W[i] != i) {
        printf("-1\n");
        return 0;}
    for(int i =0; i < N; i++) {
        if(i > 0) printf(" ");
        printf("%d",V[i]+1);}
    printf("\n");
    return 0;}
        
// look at my code
// my code is amazing