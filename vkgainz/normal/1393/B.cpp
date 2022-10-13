#include <bits/stdc++.h>
using namespace std;
#define ll long long
int num4;
int num2;
int num6;
int num8;
void query(){
    if((num4 || num6 || num8) && (num2+num4*2+num6*3+num8*4)>=4){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    int n; cin >> n;
    map<int,int> freq;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        freq[a]++;
        if(freq[a]==8){
            num8++; num6--;
        }
        else if(freq[a]==6){
            num6++; num4--;
        }
        else if(freq[a]==4){
            num4++; num2--;
        }
        else if(freq[a]==2) num2++;
    }
    int q; cin >> q;
    while(q--){
        char c; cin >> c;
        int a; cin >> a;
        if(c=='+'){
            freq[a]++;
        if(freq[a]==8){
            num8++; num6--;
        }
        else if(freq[a]==6){
            num6++; num4--;
        }
        else if(freq[a]==4){
            num4++; num2--;
        }
        else if(freq[a]==2) num2++;
        }
        else{
            freq[a]--;
            if(freq[a]==1) num2--;
            else if(freq[a]==3){
                num4--; num2++;
            }
            else if(freq[a]==5){
                num6--; num4++;
            }
            else if(freq[a]==7){
                num8--; num6++;
            }
        }
        query();
    }

}