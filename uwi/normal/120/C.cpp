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
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;

int main() {
    FILE *fp ;
    
    fp = fopen("input.txt","r") ;
    
    
    int n,k;
    fscanf(fp,"%d%d",&n,&k);
    
    vector<int> hunny;
    for(int a=0; a<n; a++) {
        int p;
        fscanf(fp,"%d",&p);
        hunny.push_back(p) ;
    }
    fclose(fp) ;
    
    
    int ret = 0;
    for(int a=0; a<n; a++) {
        if(hunny[a]>=k*3) ret += hunny[a]-k*3 ;
        else ret += hunny[a]%k ;
        
    }
    
    fp = fopen("output.txt","w") ;
    fprintf(fp,"%d\n",ret);
    fclose(fp) ;
    
    
    return 0;
}