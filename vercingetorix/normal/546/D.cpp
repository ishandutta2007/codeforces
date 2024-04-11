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

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    std::vector<int> praz(5000001,0);
    std::vector<bool> isp(5000001,false);
    
    std::vector<int> p;
    p.pb(2);
    int i=3;
    praz[2]=1;
    int curpi = 0;
    while(i<=5000000){
        int curp=p[curpi];
        while(i<=min(5000000, curp*curp)) {
            bool f=false;
            for(int j=0; j<=curpi; j++) if(i%p[j]==0){
                f=true;
                praz[i]=1+praz[i/p[j]];
                break;
            }
            if(f) {
                i++;
                continue;
                
            }
            p.push_back(i);
            praz[i]=1;
            i++;
        }
        curpi++;
    }
    
    int t;
    
    vll csum(5000001,0);
    ll sum=0;
    for(int i=2; i<=5000000; i++) {
        sum+=praz[i];
        csum[i]=sum;
    }
    int a,b;
    scanf("%d\n", &t);
    for(int i=0; i<t; i++) {
        scanf("%d %d\n", &a, &b);
        printf("%I64d\n", csum[a]-csum[b]);
    }
   // for(int i=0; i<10;i++) cout<<praz[i]<<"        "<<csum[i]<<endl;
}