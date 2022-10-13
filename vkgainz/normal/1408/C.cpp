#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a;
int n,l;
pair<double,double> meet(double t){
    long double p1 = 0;
    int currSpeed = 1;
    double t1 = 0;
    for(int i=0;i<=n;i++){
        if(t1+(a[i+1]-a[i])*1.0/currSpeed<=t){
            t1 = t1+(a[i+1]-a[i])*1.0/currSpeed;
            p1 = a[i+1];
            ++currSpeed;
        }
        else{
            p1 = p1+currSpeed*1.0*(t-t1);
            t1 = t;
        }
    }
    p1+=currSpeed*1.0*(t-t1);
    long double p2 = l;
    currSpeed = 1;
    double t2 = 0;
    for(int i=n+1;i>=1;i--){
        if(t2+(a[i]-a[i-1])*1.0/currSpeed<=t){
            t2 = t2+(a[i]-a[i-1])*1.0/currSpeed;
            p2 = a[i-1];
            ++currSpeed;
        }
        else{
            p2 = p2-currSpeed*1.0*(t-t2);
            t2 = t;
        }
    }
    p2-=currSpeed*1.0*(t-t2);
    
    return {p1,p2};
}
double binarySearch(double lo,double hi){
    double mid = (lo+hi)/2;
    auto it = meet(mid);
    if(abs(lo-hi)<=0.0000001) return mid;
    if(it.first==it.second) return mid;
    if(it.first<it.second) return binarySearch(mid,hi);
    return binarySearch(lo,mid);
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> l;
        a.clear();
        a.push_back(0);
        for(int i=0;i<n;i++){
            int x; cin >> x;
            a.push_back(x);
        }
        a.push_back(l);
        cout << setprecision(15);
        cout << binarySearch(0,1000000000) << endl;
    }
}