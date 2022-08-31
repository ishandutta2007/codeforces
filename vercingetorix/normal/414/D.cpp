#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);

}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  int n,m,k,p;
  m=0;
 //int ans=200000000;

 //cin >> n>> m >> k;
 cin>>n>>k>>p;

std::vector<std::vector<int>> ch(n+1);
std::vector<int> par(n+1);
std::vector<std::vector<int>> nb(n+1);
std::vector<std::vector<int>> lvl(n+1);
std::vector<int> v_lvl(n+1,0);
m=1;
lvl[1].push_back(1);
v_lvl[1]=1;
for(int i=1;i<n;i++){
    int u,v;
    cin >>u>>v;
    nb[u].push_back(v);
    nb[v].push_back(u);
    //xp;
}
int l=2;

while(m<n){
    for(int k=0; k<lvl[l-1].size(); k++){
        int v=lvl[l-1][k];
        for(int h=0; h<nb[v].size();h++){
            if(v_lvl[nb[v][h]]==0){
                v_lvl[nb[v][h]]=l;
                lvl[l].push_back(nb[v][h]);
                m++;
                ch[v].push_back(nb[v][h]);
                par[nb[v][h]]=v;
            }
        }
    }
    l++;
}
l--;
std::vector<long long> lsize(l+1);
for(int i=1; i<=l;i++) lsize[i]=lvl[i].size();
std::reverse(lsize.begin(), lsize.end());
std::vector<long long> csum(l+1);
std::vector<long long> csumw(l+1);
long long sum=0;
long long sumw=0;
csum[0]=0;
csumw[0]=0;
for(long long i=1; i<=l;i++){
    sum+=lsize[i-1];
    csum[i]=sum;
    sumw+=lsize[i-1]*i;
    csumw[i]=sumw;
}
long long ans=0;

for(long long x=1; x<l;x++){
    int curymax=l-1;
    int curymin=x;
    while((curymax-curymin)>=1){
        int cury=(curymax+curymin)/2;
        long long num=csum[cury]-csum[x-1];
        if(num>=k){
            curymax=cury;
            continue;
        }
        long long cost=csumw[cury]-csumw[x-1]-x*num;
        if(cost>=p){
            curymax=cury;
            continue;
        }
        curymin=cury+1;

    }
    int y=curymax;
    long long num=csum[y-1]-csum[x-1];
    long long cost=csumw[y-1]-csumw[x-1]-x*num;
    long long pcost=p-cost;
    if(y>x) pcost/=(y-x);
    else pcost=999999;
    long long curans=min(min(k-num,pcost),lsize[y-1])+num;
    if(curans>ans) ans=curans;

}

/*
 for(int i=0; i<n; i++){
     long long x;
     cin>>x;

 }*/

cout<<ans;
  return 0;
}