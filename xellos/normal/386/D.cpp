#include <bits/stdc++.h>
using namespace std;

void sI(int &a, int &b, int &c) {
    if(a > b) swap(a,b);
    if(a > c) swap(a,c);
    if(b > c) swap(b,c);}

int main() {
    int N,a,b,c;
    cin >> N >> a >> b >> c;
    a--, b--, c--;
    queue<int> q;
    sI(a,b,c);
    q.push(a*N*N+b*N+c);
    vector<string> V(N);
    for(int i =0; i < N; i++) cin >> V[i];
    int D[100][100][100];
    int ako[100][100][100];
    for(int i =0; i < N*N*N; i++) D[i%N][(i/N)%N][i/N/N] =1000000000;
    D[a][b][c] =0;
    
    while(!q.empty()) {
        a =q.front()/N/N, b =(q.front()/N)%N, c =q.front()%N;
        for(int i =0; i < N; i++) if(i != a && i != b && i != c)
            if(V[b][c] == V[a][i]) {
                int x =i, y =b, z =c;
                sI(x,y,z);
                if(D[x][y][z] > D[a][b][c]+1) {
                    D[x][y][z] =D[a][b][c]+1;
                    ako[x][y][z] =q.front();
                    q.push(x*N*N+y*N+z);}
                }
        for(int i =0; i < N; i++) if(i != a && i != b && i != c)
            if(V[a][c] == V[b][i]) {
                int x =a, y =i, z =c;
                sI(x,y,z);
                if(D[x][y][z] > D[a][b][c]+1) {
                    D[x][y][z] =D[a][b][c]+1;
                    ako[x][y][z] =q.front();
                    q.push(x*N*N+y*N+z);}
                }
        for(int i =0; i < N; i++) if(i != a && i != b && i != c)
            if(V[a][b] == V[c][i]) {
                int x =a, y =b, z =i;
                sI(x,y,z);
                if(D[x][y][z] > D[a][b][c]+1) {
                    D[x][y][z] =D[a][b][c]+1;
                    ako[x][y][z] =q.front();
                    q.push(x*N*N+y*N+z);}
                }
        q.pop();}

    if(D[0][1][2] > 100000000) cout << "-1\n";
    else {
        cout << D[0][1][2] << "\n";
        int akt =N+2;
        vector< pair<int,int> > moves(D[0][1][2]);
        for(int i =0; i < D[0][1][2]; i++) {
            set<int> s1,s2;
            a =akt/N/N, b =(akt/N)%N, c =akt%N;
            s1.insert(a); s1.insert(b); s1.insert(c);
            int x =ako[a][b][c]/N/N, y =(ako[a][b][c]/N)%N, z =ako[a][b][c]%N;
            s2.insert(x); s2.insert(y); s2.insert(z);
            if(s1.find(x) == s1.end()) moves[i].first =x;
            if(s1.find(y) == s1.end()) moves[i].first =y;
            if(s1.find(z) == s1.end()) moves[i].first =z;
            if(s2.find(a) == s2.end()) moves[i].second =a;
            if(s2.find(b) == s2.end()) moves[i].second =b;
            if(s2.find(c) == s2.end()) moves[i].second =c;
            akt =ako[a][b][c];}
        for(int i =D[0][1][2]-1; i >= 0; i--)
            cout << moves[i].first+1 << " " << moves[i].second+1 << "\n";
        }
    return 0;}