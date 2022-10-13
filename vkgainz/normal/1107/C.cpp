#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    string s;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> s;
    int i= 0;
    ll ret = 0;
    while(i<n){
        multiset<int, greater<int>> m;
        int j = i;
        while(j<n){
            if(s[j]==s[i]){
                m.insert(a[j]);
                j++;
            }
            else{
                break;
            }
        }
        auto it = m.begin();
        int temp = k;
        while(temp>0 && it!=m.end()){
            temp--;
            ret+=*it;
            m.erase(it++);
        }
        i= j;
    }
    cout << ret << endl;
}