#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;
const int inf=1e9+10;

int n,a[N];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cout<<"1 ";
  for(int i=1,j=n;i<=n;i++){
    int val;
    cin>>val;
    a[val]=1;
    while (a[j]) j--;
    cout<<1+i-(n-j)<<" ";
  }
}