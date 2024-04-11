#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

double rw[101][101][101];
double sw[101][101][101];
double pw[101][101][101];

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    for(int i=0; i<101; i++) for(int j=0; j<101; j++) for(int k=0; k<101; k++) {
        rw[i][j][k]=0.;
        sw[i][j][k]=0.;
        pw[i][j][k]=0.;
    }
    for(int r=0; r<101; r++) {
        for(int s=0; s<101; s++) {
            for(int p=0; p<101; p++) {
                if((r>0)&&(s==0)&&(p==0)) {
                    rw[r][s][p]=1.;
                    continue;
                }
                if((r==0)&&(s>0)&&(p==0)) {
                    sw[r][s][p]=1.;
                    continue;
                }
                if((r==0)&&(s==0)&&(p>0)) {
                    pw[r][s][p]=1.;
                    continue;
                }
                double rs=(double)(r*s)/(double)(r*s+p*r+s*p);
                double ps=(double)(p*s)/(double)(r*s+p*r+s*p);
                double rp=(double)(r*p)/(double)(r*s+p*r+s*p);
                if ((r*s)>0) {
                    rw[r][s][p]+=rw[r][s-1][p]*rs;
                    sw[r][s][p]+=sw[r][s-1][p]*rs;
                    pw[r][s][p]+=pw[r][s-1][p]*rs;
                }
                if ((p*s)>0) {
                    rw[r][s][p]+=rw[r][s][p-1]*ps;
                    sw[r][s][p]+=sw[r][s][p-1]*ps;
                    pw[r][s][p]+=pw[r][s][p-1]*ps;
                }
                if ((r*p)>0) {
                    rw[r][s][p]+=rw[r-1][s][p]*rp;
                    sw[r][s][p]+=sw[r-1][s][p]*rp;
                    pw[r][s][p]+=pw[r-1][s][p]*rp;
                }
            }
        }
    }
    int r,s,p;
    cin>>r>>s>>p;
    printf("%.10lf %.10lf %.10lf", rw[r][s][p], sw[r][s][p], pw[r][s][p]);
    
}