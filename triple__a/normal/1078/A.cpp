#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double a,b,c;
pair<double,double> A,B;

pair<double,double> calc(pair<double,double> x,int t){
    if (t){
        return {x.F,(-c-a*x.F)/b};
    }
    else{
        return {(-c-b*x.S)/a,x.S};
    }
}

double dist(pair<double,double> u,pair<double,double> v){
    return sqrt((u.F-v.F)*(u.F-v.F)+(u.S-v.S)*(u.S-v.S));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
    cin>>a>>b>>c>>A.F>>A.S>>B.F>>B.S;
    if (a==0||b==0){
        cout<<fabs(A.F-B.F)+fabs(A.S-B.S);
        return 0;
    }
    double ans=fabs(A.F-B.F)+fabs(A.S-B.S);
    for (int i=0;i<2;++i){
        for (int j=0;j<2;++j){
            ans=min(ans,dist(A,calc(A,i))+dist(calc(A,i),calc(B,j))+dist(calc(B,j),B));
        }
    }
    cout<<ans<<endl;
    return 0;
}