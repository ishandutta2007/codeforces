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

cin>>k;
vb e(1001*1001,false);
n=2;
int d=0;
while(k>0){
    int s=k%10;
    if(k==10){
        s=10;
        k=0;
    }
    k/=10;
    
    if(s==0) {
        d++;
        continue;

    }
    int newn=n;
    for(int i=1; i<=s; i++) {
        e[1*1001+n+i]=true;
        e[(n+i)*1001+1]=true;
    }
    newn+=s;
    /*if(d>0){
        for(ini i=1; i<=s; i++) for(int j=1; j<=10; j++) {
            e((newn+j)*1001+n+i)=true;
            e((n+i)*1001+newn+j)=true;
        }
    }*/
    for(int k=1; k<=d;k++){
        for(int i=0; i<s; i++) for(int j=1; j<=10; j++) {
            e[(newn+j)*1001+newn-i]=true;
            e[(newn-i)*1001+newn+j]=true;
        }
        newn+=10;
        s=10;
    }
    for(int k=1; k<=8-d;k++){
        for(int i=0; i<s; i++) for(int j=1; j<=1; j++) {
            e[(newn+j)*1001+newn-i]=true;
            e[(newn-i)*1001+newn+j]=true;
        }
        newn+=1;
        s=1;
    }
    for(int i=0; i<s; i++){
        e[2*1001+newn-i]=true;
        e[(newn-i)*1001+2]=true;
    }
    n=newn;
    d++;
}
cout<<n<<endl;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(e[i*1001+j]) cout<<'Y';
        else cout<<'N';
    }
    cout<<endl;
}




  return 0;
}