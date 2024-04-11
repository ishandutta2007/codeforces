#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int> freq;
int main(){
    int n; cin >> n;
    int sum =0;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        ++freq[a[i]];
        sum+=(a[i]-i);
        sum = (sum%2+2)%2;
    }
    sort(a,a+n);
    bool start = false;
    for(int i=0;i<n;i++){
        if(freq[a[i]]>=3 || a[i]<i) start = true;
        if(freq[a[i]]>=2 && freq[a[i]-1]>0) start = true;
    }
    int x = 0;
    for(auto &it : freq){
        if(it.second>=2){
            x++;
        }
    }
    if(x>=2) start = true;
    if(start){
        cout << "cslnb" << endl;
        return 0;
    }
    if(sum) cout << "sjfnb" << endl;
    else cout << "cslnb" << endl;
}