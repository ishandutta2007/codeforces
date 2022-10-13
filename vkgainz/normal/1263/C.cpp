#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    int t;
    cin >> t;
    while(t--){
    cin >> n;
    set<int> s;
    for(int i=1;i<=sqrt(n);i++){
        s.insert(n/i);
    }
    for(int x=0;x<=sqrt(n);x++){
        s.insert(x);
    }
    auto it = s.begin();
    cout << s.size() << endl;
    while(it!=s.end()){
        cout << *it << " " ;
        it++;
    }
    cout << endl;
    }
}