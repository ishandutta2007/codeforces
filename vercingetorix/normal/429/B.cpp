#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
 
  int n,m,k;
//int ans=0;
  //cin >> a >> k;

cin>>n>>m;

std::vector<int> a(n*m);
std::vector<int> dl(n*m,0);
std::vector<int> dr(n*m,0);
std::vector<int> ul(n*m,0);
std::vector<int> ur(n*m,0);

//std::string s;
int ans=0;
for(int i=0;i<n;i++){
    for(int j=0; j<m; j++){
        cin>>a[i*m+j];
    }
    /*int u,v,x;
    cin >>u>>v>>x;
    d[i]=x;
    g[i]=y;
    //xp;*/
}
dr[0]=a[0];
ur[(n-1)*m]=a[(n-1)*m];
dl[m-1]=a[m-1];
ul[m*n-1]=a[m*n-1];

for(int i=1;i<n;i++){
    dr[i*m]=dr[(i-1)*m]+a[i*m];
    dl[i*m+m-1]=dl[(i-1)*m+m-1]+a[i*m+m-1];
}
for(int i=n-2;i>=0;i--){
    ur[i*m]=ur[(i+1)*m]+a[i*m];
    ul[i*m+m-1]=ul[(i+1)*m+m-1]+a[i*m+m-1];
}
for(int j=1;j<m;j++){
    dr[j]=dr[j-1]+a[j];
    ur[(n-1)*m+j]=ur[(n-1)*m+j-1]+a[(n-1)*m+j];
}
for(int j=m-2;j>=0;j--){
    dl[j]=dl[j+1]+a[j];
    ul[(n-1)*m+j]=ul[(n-1)*m+j+1]+a[(n-1)*m+j];
}

for(int i=1;i<n;i++){
    for(int j=1; j<m; j++){
        dr[i*m+j]=max(dr[(i-1)*m+j], dr[i*m+j-1]) + a[i*m+j];
    }
}

for(int i=n-2;i>=0;i--){
    for(int j=1; j<m; j++){
        ur[i*m+j]=max(ur[(i+1)*m+j], ur[i*m+j-1]) + a[i*m+j];
    }
}

for(int i=n-2;i>=0;i--){
    for(int j=m-2; j>=0; j--){
        ul[i*m+j]=max(ul[(i+1)*m+j], ul[i*m+j+1]) + a[i*m+j];
    }
}

for(int i=1;i<n;i++){
    for(int j=m-2; j>=0; j--){
        dl[i*m+j]=max(dl[(i-1)*m+j], dl[i*m+j+1]) + a[i*m+j];
    }
}

for(int i=1;i<n-1;i++){
    for(int j=1; j<m-1; j++){
        int x=dr[(i-1)*m+j]+ul[(i+1)*m+j]+ur[i*m+j-1]+dl[i*m+j+1];
        if(x>ans) ans=x;
        x=dl[(i-1)*m+j]+ur[(i+1)*m+j]+dr[i*m+j-1]+ul[i*m+j+1];
        if(x>ans) ans=x;
    }

}
  cout << ans;
  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}