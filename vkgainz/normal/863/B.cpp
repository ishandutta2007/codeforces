#include <bits/stdc++.h>
using namespace std;
#define ll long long
int compute(vector<int> &temp,int b1,int b2){
    vector<int> x;
    for(int i=0;i<temp.size();i++){
        if(i!=b1 && i!=b2){
            x.push_back(temp[i]);
        }
    }
    int res = 0;
    for(int i=0;i<x.size();i+=2){
        res+=x[i+1]-x[i];
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    vector<int> vals;
    for(int i=0;i<2*n;i++){
        int t;
        cin >> t;
        vals.push_back(t);
    }
    sort(vals.begin(),vals.end());
    int ret = 100000000;
    for(int i=0;i<2*n;i++){
        for(int j=i+1;j<2*n;j++){
            ret =min(ret,compute(vals,i,j));
        }
    }
    cout << ret << endl;
}