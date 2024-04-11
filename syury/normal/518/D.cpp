#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int n,t;
double p;
vector<vector<double> >ans;
double e=0.0;

int main(){
    cin>>n>>p>>t;
    ans.resize(t+1);
    for(int i=0;i<=t;i++){
        ans[i].resize(n+1);
        for(int j=0;j<=n;j++){
            if(i<j){ans[i][j]=0.0;continue;}
            if(i==0){ans[i][j]=1.0;continue;}
            ans[i][j]=(j==n)? ans[i-1][j] : ans[i-1][j]*(1.0-p);
            ans[i][j]+=(j==0)? 0.0 : ans[i-1][j-1]*p;
        }
    }
    for(int i=0;i<=n;i++){e+=ans[t][i]*i;}
    cout<<setprecision(8)<<e;
    return 0;
}