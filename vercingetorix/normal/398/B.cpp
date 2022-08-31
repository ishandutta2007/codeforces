#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif




  int n,m,k;
//int ans=0;
  //cin >> a >> k;
  k=0;
cin>>n>>m;

std::vector<double> p((n+1)*(n+1),0);
for(int i=1;i<=n;i++){
    int u=n-i;
    double pi=(double)i/(double) n;
    double pu=(double)u/(double) n;
    double x=(1.+pi*p[i-1])/(1.-pu);
    p[i]=x;
    p[(n+1)*i]=x;

}
for(int i=1;i<=n;i++){
    for(int j=1; j<=n; j++){
        int u=n-i;
        int v=n-j;
        double pi=(double)i/(double) n;
        double pj=(double)j/(double) n;
        double pu=(double)u/(double) n;
        double pv=(double)v/(double) n;
        p[i*(n+1)+j]=(1.+pi*pv*p[(i-1)*(n+1)+j]+pu*pj*p[i*(n+1)+j-1]+pi*pj*p[(i-1)*(n+1)+j-1])/(1.-pu*pv);
    }


}




vi c(n+1,false);
vi r(n+1, false);
for(int i=0; i<m; i++){
    int a,b;
    cin>>a>>b;
    c[a]=true;
    r[b]=true;
}

int cp=0, rp=0;
for(int i=1;i<=n;i++){
    if(c[i]) cp++;
    if(r[i]) rp++;
}
int cup=n-cp;
int rup=n-rp;
printf("%.8f",p[cup*(n+1)+rup]);

  return 0;
}