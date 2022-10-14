#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> d;
    for(int i=1;i<=n;i++)if(n%i==0)d.pb(i);
    for(auto c:d){reverse(s.begin(),s.begin()+c);}
    cout<<s<<endl;
    return 0;
}