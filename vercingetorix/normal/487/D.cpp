#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

int table[100002][12];
int destx[100002][12];
int desty[100002][12];
int n,m,q,t;

void go(int a, int b){
    vi bux(11);
    vi buy(11);
    for(int i=1;i<=m;i++){
        bux[i]=destx[a-1][i];
        destx[a-1][i]=a-1;
        buy[i]=desty[a-1][i];
        desty[a-1][i]=i;
    }
    for(int i=a; i<=b; i++){
        int rbef=0;
        for(int j=1;j<=m;j++){
            if(table[i][j]==1){
                rbef++;
                continue;
            }
            else if(table[i][j]==0){
                for(int k=0; k<=rbef; k++){
                    destx[i][j-k]=destx[i-1][j];
                    desty[i][j-k]=desty[i-1][j];
                }
                rbef=0;
            }
            else if(table[i][j]==-1){
                if(rbef==0){
                    destx[i][j]=destx[i][j-1];
                    desty[i][j]=desty[i][j-1];
                }
                else{
                    for(int k=0; k<=rbef; k++){
                        destx[i][j-k]=-1;
                        desty[i][j-k]=-1;
                    }
                    rbef=0;
                }
            }
        }
        if(rbef>0){
            for(int k=0; k<rbef; k++){
                destx[i][m-k]=i;
                desty[i][m-k]=m+1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        destx[a-1][i]=bux[i];
        desty[a-1][i]=buy[i];
    }
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
    
 
    cin>>n>>m>>q;
    for(int i=0;i<=100000;i++) {
        destx[i][0]=i;
        desty[i][0]=0;        
    }
    for(int i=0;i<=100000;i++) {
        destx[i][m+1]=i;
        desty[i][m+1]=m+1;        
    }
    for(int i=1;i<=m;i++) {
        destx[0][i]=0;
        desty[0][i]=i;        
    }
    char c;
    for(int i=1;i<=n;i++) 
            for(int j=1;j<=m;j++) {
        cin>>c;
        if(c=='<') table[i][j]=-1;
        else if(c=='>') table[i][j]=1;
        else if(c=='^') table[i][j]=0;         
    }
    const int kChunkSize = 500;
    for(int i=1; i<=n; i+=kChunkSize){
        go(i,max(i+kChunkSize-1, n));
    }    
    int x,y;
    for(int i=0; i<q; i++){
        cin>>c;
        if(c=='A'){
            cin>>x>>y;
            int posx=destx[x][y];
            int posy=desty[x][y];
            while((posx>0)&&(posy>0)&&(posy<=m)){
                int oldposx=posx;
                posx=destx[posx][posy];
                posy=desty[oldposx][posy];
            }
            cout<<posx<<" "<<posy<<endl;
        }
        else if(c=='C') {
            cin>>x>>y>>c;
            if(c=='<') table[x][y]=-1;
            else if(c=='>') table[x][y]=1;
            else if(c=='^') table[x][y]=0;
            int alim = ((x-1)/kChunkSize)*kChunkSize+1;
            int blim = min(alim+kChunkSize-1, n);
            go(alim,blim);
        }
    }


}