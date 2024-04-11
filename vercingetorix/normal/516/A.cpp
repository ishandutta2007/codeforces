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
int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

long long n;
int a[8];
a[2]=0;
a[3]=0;
a[5]=0;
a[7]=0;
cin>>n;
cin>>n;
while(n>0){
    ll x=n%10;
    n/=10;
    for(int i=2; i<=x; i++){
        if(i==2) a[2]++;
        else if(i==3) a[3]++;
        else if(i==5) a[5]++;
        else if(i==7) a[7]++;
        else if(i==4) a[2]+=2;
        else if(i==8) a[2]+=3;
        else if(i==9) a[3]+=2;
        else if(i==6) {
            a[3]++;
            a[2]++;
        }
    }
}
string s;
while(a[7]>0) {
    s.pb('7');
    a[7]--;
    a[5]--;
    a[3]-=2;
    a[2]-=4;
}
while(a[5]>0) {
    s.pb('5');
    a[5]--;
    a[3]--;
    a[2]-=3;
}
while(a[3]>0) {
    s.pb('3');
    a[2]--;
    a[3]--;
}
while(a[2]>0) {
    s.pb('2');
    a[2]--;
}
cout<<s;
return 0;
}