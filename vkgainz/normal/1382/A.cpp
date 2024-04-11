#include <bits/stdc++.h>
using namespace std;
int t;
int n,m;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<m;i++){
            cin >> b[i];
        }
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        int put = -1;
        for(int i=0;i<m;i++){
            if(s.find(b[i])!=s.end()){
                put = b[i];
            }
        }
        if(put!=-1){
            cout << "YES" << endl;
            cout << 1 << " " << put << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
}