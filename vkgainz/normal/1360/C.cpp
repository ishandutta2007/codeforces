#include <iostream>
#include <vector>
using namespace std;
int t, n ;
void solve(vector<int> odd, vector<int> even){
    if(even.size()%2==0){
        cout << "YES" << endl;
    }
    else{
        bool work = false;
        for(int i=0;i<even.size();i++){
            for(int j=0;j<odd.size();j++){
                if((even[i]-odd[j])==1 ||(odd[j]-even[i])==1){
                    work = true;

                    
                }
            }
        }
        if(work){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
int main(){
    cin >>t;
    while(t>0){
        t--;
        cin >> n;
        int a[51];
        vector<int> odd, even;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]%2==0){
                even.push_back(a[i]);
            
            }
            else{
                odd.push_back(a[i]);               
            }

        }
        solve(odd, even);
    }
}