#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int w[n];
        for(int i=0;i<n;i++)
            cin >> w[i];
        set<int> make;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                make.insert(w[i]+w[j]);
        }
        int most = 0;
        sort(w,w+n);
        for (auto &it : make){
            int i =0;
            int j = n-1;
            int temp =0;
            while(i<j){
                if(w[i]+w[j]==it){
                    i++;
                    j--;
                    temp++;
                }
                else if(w[i]+w[j]<it){
                    i++;
                }
                else{
                    j--;
                }
                most = max(most,temp);
            }
        }
        cout << most << endl;
        
    }
}