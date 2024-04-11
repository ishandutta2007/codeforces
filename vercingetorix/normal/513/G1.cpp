#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvll;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
int p[30];
int n,d,x,y,k;
double M;

void go(){
    if(k==0){
        int cn=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(p[i]>p[j]) cn++;
            }
        }
        M+=cn;
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            k--;
            for(int m=i; m<=i+(j-i+1)/2-1; m++){
                int s=p[m];
                p[m]=p[j+i-m];
                p[j+i-m]=s;
            }
            go();
            for(int m=i; m<=i+(j-i+1)/2-1; m++){
                int s=p[m];
                p[m]=p[j+i-m];
                p[j+i-m]=s;
            }
            k++;
        }
    }
}

int main()
{
/*#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif*/
  //GGGGG
  M=0;
int ans = 0;
cin>>n>>k;
for(int i=0; i<n; i++) cin>>p[i];
go();
for(int i=0; i<k; i++) M/=((n*(n+1))/2);
printf("%.10f", M);
 return 0;
}