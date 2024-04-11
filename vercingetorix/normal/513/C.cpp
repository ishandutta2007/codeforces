#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
ll mod=1000000007;

int L[5];
int R[5];
int n;

double pr_i_gr_n(int i, int nn){
    if(R[i]<nn) return 0.;
    if(L[i]>=nn) return 1.;
    return((double)(R[i]-nn+1)/(double)(R[i]-L[i]+1));
}

double sec_pr_gr_n(int nn) {
    double p=0;
    for(int i=0; i<n; i++){
        double pp=1;
        for(int j=0; j<n; j++){
            if(j==i) pp*=pr_i_gr_n(j, nn);
            else pp*=(1-pr_i_gr_n(j,nn));
        }
        p+=pp;
    }
    double ppp=1;
    for(int j=0; j<n; j++){
        ppp*=(1-pr_i_gr_n(j,nn));
    }
    p+=ppp;
    return (1-p);
}


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

int ans=0;
int a,b,k;
cin>>n;

for(int i=0; i<n; i++) {
    cin>>L[i]>>R[i];
}

double p=0;
for(int i=1; i<=10000; i++) p+=sec_pr_gr_n(i);
printf("%.10f", p);




return 0;


}