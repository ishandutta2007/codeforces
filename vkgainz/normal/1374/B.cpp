#include <bits/stdc++.h>
using namespace std;
int n, x, y;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b = 0;
        int temp = n;
        int a =0;
        while(temp>0){
            if(temp%2==0){
                temp/=2;
                a++;
            }
            else if(temp%3==0){
                temp/=3;
                b++;
            }
            else{
                break;
            }
            
        }

        if(temp!=1){
            cout << -1 << endl;
        }
        else{
            if(b<a){
                cout << -1 << endl; 
            }
            else{
                cout << 2*b-a << endl;
            }
        }
        }
    }