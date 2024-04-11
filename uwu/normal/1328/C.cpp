#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t; cin >> t;
    for (int q=0;q<t;++q){
        int n; cin >> n;
        string uwu; cin >> uwu;
        bool larger=false;
        int a[n], b[n];
        for (int i=0;i<n;++i){
            if (uwu[i]=='0'){
                a[i]=0;
                b[i]=0;
            }
            else if (uwu[i]=='1'){
                if (larger){
                    b[i]=1;
                    a[i]=0;
                }
                else{
                    larger=true;
                    a[i]=1;
                    b[i]=0;
                }
            }
            else if (uwu[i]=='2'){
                if (larger){
                    b[i]=2;
                    a[i]=0;
                }
                else{
                    b[i]=1;
                    a[i]=1;
                }
                
            }
        }
        bool seen=false;
        for (int i=0;i<n;++i){
            if (a[i]==0&&!seen) continue;
            seen=true;
            cout << a[i];
        }
        cout << '\n';
        seen=false;
        for (int i=0;i<n;++i){
            if (b[i]==0&&!seen) continue;
            seen=true;
            cout << b[i];
        }
        cout << '\n';
    }
}