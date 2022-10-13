#include <bits/stdc++.h>
using namespace std;


int n, a[500001];

int main(){
    vector<int> p({4,8,15,16,23,42});
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i] = lower_bound(p.begin(),p.end(),a[i])-p.begin();
    
    }
    vector<int> seq(6);
    for(int i=0;i<n;i++){
        if(a[i]==0){
            ++seq[0];
        }
        else{
            if(seq[a[i]-1]>0){
                --seq[a[i]-1];
                ++seq[a[i]];
            }
        }
    }
    cout << n - seq[5]*6 << endl;

}