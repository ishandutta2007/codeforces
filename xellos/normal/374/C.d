import std.stdio;
import std.string;
import std.algorithm;

bool solve(ref int[] ans, ref int[][] G, ref int[] vis, int x) {
    if(vis[x]) return false;
    if(ans[x] != -1) return true;
    ans[x] =1;
    vis[x] =true;
    for(int i =0; i < G[x].length; i++) 
        if(!solve(ans,G,vis,G[x][i])) return false;
    for(int i =0; i < G[x].length; i++) ans[x] =max(ans[x],ans[G[x][i]]+1);
    vis[x] =false;
    return true;}

void main() {
    int N,M;
    scanf(" %d %d\n",&N,&M);
    string A[]; A.length =N;
    for(int i =0; i < N; i++) A[i] =chomp(readln());

    int G[][]; G.length =N*M;
    int dx[] =[1,-1,0,0];
    int dy[] =[0,0,1,-1];
    for(int i =0; i < N; i++) for(int j =0; j < M; j++)
        for(int k =0; k < 4; k++) {
            int x =i+dx[k], y =j+dy[k];
            if(x < 0 || y < 0 || x >= N || y >= M) continue;
            if(A[i][j] == 'D' && A[x][y] == 'I') G[i*M+j] ~=(x*M+y);
            else if(A[i][j] == 'I' && A[x][y] == 'M') G[i*M+j] ~=(x*M+y);
            else if(A[i][j] == 'M' && A[x][y] == 'A') G[i*M+j] ~=(x*M+y);
            else if(A[i][j] == 'A' && A[x][y] == 'D') G[i*M+j] ~=(x*M+y);}
    
    int ans[]; ans.length =N*M;
    int vis[]; vis.length =N*M;
    for(int i =0; i < N*M; i++) ans[i] =-1, vis[i] =false;
    for(int i =0; i < N*M; i++) if(ans[i] == -1) 
        if(!solve(ans,G,vis,i)) {
            writeln("Poor Inna!");
            return;}
    int ansR =0;
    for(int i =0; i < N*M; i++) 
        if(A[i/M][i%M] == 'D') ansR =max(ansR,ans[i]/4);
    if(ansR == 0) writeln("Poor Dima!");
    else writeln(ansR);}