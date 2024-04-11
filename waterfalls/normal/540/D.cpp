#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Prob { double r=0,s=0,p=0; };

int rr,ss,pp;
Prob probs[101][101][101];
int done[101][101][101];

void solve(int r, int s, int p) {
    if (done[r][s][p]) return;
    if (r==0 && s==0) done[r][s][p] = 1, probs[r][s][p].p = 1;
    if (s==0 && p==0) done[r][s][p] = 1, probs[r][s][p].r = 1;
    if (p==0 && r==0) done[r][s][p] = 1, probs[r][s][p].s = 1;
    if (!done[r][s][p]) {
        if (r) {
            double rd = 1.*r*p/(r*s+s*p+p*r);
            solve(r-1,s,p);
            probs[r][s][p].r+=rd*probs[r-1][s][p].r;
            probs[r][s][p].s+=rd*probs[r-1][s][p].s;
            probs[r][s][p].p+=rd*probs[r-1][s][p].p;
        }
        if (s) {
            double sd = 1.*s*r/(r*s+s*p+p*r);
            solve(r,s-1,p);
            probs[r][s][p].r+=sd*probs[r][s-1][p].r;
            probs[r][s][p].s+=sd*probs[r][s-1][p].s;
            probs[r][s][p].p+=sd*probs[r][s-1][p].p;
        }
        if (p) {
            double pd = 1.*p*s/(r*s+s*p+p*r);
            solve(r,s,p-1);
            probs[r][s][p].r+=pd*probs[r][s][p-1].r;
            probs[r][s][p].s+=pd*probs[r][s][p-1].s;
            probs[r][s][p].p+=pd*probs[r][s][p-1].p;
        }
        done[r][s][p] = 1;
    }
}

int main() {
    scanf("%d%d%d",&rr,&ss,&pp);
    solve(rr,ss,pp);
    printf("%1.9f %1.9f %1.9f\n",probs[rr][ss][pp].r,probs[rr][ss][pp].s,probs[rr][ss][pp].p);
}