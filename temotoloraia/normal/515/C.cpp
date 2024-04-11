#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    string x,a[10]= {"","","2","3","223","5","53","7","2227","3327"};
    int l ;
    string n ;
    cin>>l>>n;
    for (int i=0;i<n.size();i++){
        x+=a[n[i]-'0'];
    }
    sort(x.begin(),x.end(),greater<char>());
    cout<<x;

}