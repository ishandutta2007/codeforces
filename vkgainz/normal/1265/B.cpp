#include <bits/stdc++.h>
using namespace std;

int t;
int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p[n];
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        int pos[n];
        for(int i=0;i<n;i++){
            p[i]--;
            pos[p[i]] = i;
        }
        int minPos = n+1;
        int maxPos = -1;
        string ret;
        for(int i=0;i<n;i++){
            minPos = min(minPos,pos[i]);
            maxPos = max(maxPos,pos[i]);
            if((maxPos-minPos+1)!=i+1){
                ret+='0';
            }
            else{
                ret+='1';
            }
               
        }
        cout << ret << endl;
    }
            
}