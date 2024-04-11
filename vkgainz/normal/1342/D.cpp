#include <bits/stdc++.h>
using namespace std;
int m[200001];
int c[200001];
int n,k;
bool works(int x){
    if(x==0) return false;
    int curr = 0;
    vector<int> temp[x];
    for(int i=n-1;i>=0;i--){
        temp[curr].push_back(m[i]);
        curr++;
        curr%=x;
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<temp[i].size();j++){
            if((j+1)>c[temp[i][j]-1]) return false;
        }
    }
    return true;
}
int binarySearch(int lo,int hi){
    int mid = (lo+hi)/2;
    if(works(mid)){
        if(!works(mid-1)) return mid;
        return binarySearch(lo,mid-1);
    }
    return binarySearch(mid+1,hi);
}
int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> m[i];
    for(int i=0;i<k;i++)
        cin >> c[i];
    sort(m,m+n);
    int x = binarySearch(1,n);
    vector<int> temp[x];
    int curr =0;
    for(int i=n-1;i>=0;i--){
        temp[curr].push_back(m[i]);
        curr++;
        curr%=x;
    }
    cout << x << endl;
    for(auto &it : temp){
        cout << it.size() << " ";
        for(auto &it : it){
            cout << it << " ";
        }
        cout << endl;
    }
    
}