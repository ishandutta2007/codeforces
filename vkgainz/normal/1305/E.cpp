#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int m; cin >> m;
    if(m>(n-1)/2*(n/2)){
        cout << -1 << endl;
        return 0;
    }
    int nOutput = 0;
    if(m==0){
        cout << 10000 << endl;
        for(int i=1;i<n;i++){
            cout << (10000+i) << endl;
        }
    }

    else{
        int i=0;
        int num = 0;
        while(i<n){
            i++;
            if((i-1)/2*(i/2)<=m){
                cout << i << endl;
                nOutput++;
            }
            else{
                i--;
                m-=(i-1)/2*(i/2);
                int k = i+1-2*m;
                cout << (i+k) << endl;
                nOutput++;
                i++;
                for(int j=i;j<n;j++){
                    cout << (50000000+j*(i+10000)) << endl;
                    nOutput++;
                }
                break;
            }
        }
    }
}