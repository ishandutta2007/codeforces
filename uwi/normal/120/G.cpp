#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;

int main() {

    
    ifstream ifs( "input.txt" );
    
    
    
    int A[105][2], B[105][2];
    int D[105][105];
    
    for(int a=0; a<105; a++) for(int b=0; b<105; b++) D[a][b] = 0;
    
    queue < pair<string,pair<int,int> > > deck ;
    
    
    
    int n,t;
    ifs>>n>>t;
    
    for(int a=0; a<n; a++) {
    //  fscanf(fp,"%d%d%d%d" , &A[a][0] , &B[a][0] , &A[a][1] , &B[a][1]);
        ifs >> A[a][0]>> B[a][0] >> A[a][1] >> B[a][1] ;
    }
    int m;
    ifs >> m;
    for(int a=0; a<m; a++) {
        string s;
        int p;
        
        ifs >>s >> p;
        deck.push(MP(s,MP(p,a) ));
    }
    
    
    vector<string > ret[100];
    
    int team=0;
    int player=0;
    int teammate=1;
    
    int nokori = t;
    
    while(deck.size()!=0) {
        
        pair<string,pair<int,int> > tmp;
        tmp = deck.front();
        deck.pop() ;
        
        int i = team ;
        int j = player ;
        int k = tmp.second.second;
        int q = teammate ;
        int ck = tmp.second.first;
        
        nokori -= max(1, ck- (A[i][j]+B[i][q]) - D[i][k] ) ;
        
        if(nokori>=0) ret[team].push_back(tmp.first) ;
        if(nokori<=0){
            if(nokori<0) {
                D[i][k] += nokori + max(1, ck- (A[i][j]+B[i][q]) - D[i][k] );
                deck.push(tmp) ;
            }
            team ++ ;
            
            if(team==n) team = 0, swap(teammate, player) ;
            
            nokori = t;
            
        }
        
    }
    
    
    ofstream ofs("output.txt") ;
    
    for(int a=0; a<n; a++) {
        ofs<<ret[a].size();
        for(int b=0; b<ret[a].size(); b++) ofs<<" "<<ret[a][b];
        
        ofs<<" "<<endl;
        
    }
    
    
    return 0;
}