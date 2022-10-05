#include<bits/stdc++.h>
using namespace std;
int h[1500];
double res[1500];
int main(){
    int n,r;
    cin>>n>>r;
    for(int i=0;i<n;i++){
        cin>>h[i];
        double rs=r;
        for(int j=0;j<i;j++){
            int dx=abs(h[i]-h[j]);
			rs=max(rs,res[j]+sqrt(4*r*r-dx*dx));
        }
        res[i]=rs;
    }
    for(int i=0;i<n;i++) printf("%.8f ",res[i]);
    return 0;
}