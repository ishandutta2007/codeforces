#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> Rev(vector<int> a){
    vector<int> ans;
    for(int i:a){
        if(i==3||i==4||i==6||i==7||i==9){
            ans.clear();
            return ans;
        }
        if(i==0)ans.pb(0);
        if(i==1)ans.pb(1);
        if(i==2)ans.pb(5);
        if(i==5)ans.pb(2);
        if(i==8)ans.pb(8);
    }
    return ans;
}
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int h,m;cin>>h>>m;
        string s;cin>>s;
        vector<int> d;
        for(int i=0;i<5;i++){
            if(i==2)continue;
            d.pb((int)(s[i]-'0'));
        }
        int n=(d[0]*10+d[1])*m+d[2]*10+d[3];
        while(true){
            int hh=(n/m)%h,mm=n%m;
            vector<int> b;
            if(hh<10)b.pb(0);
            else b.pb(hh/10);
            b.pb(hh%10);
            if(mm<10)b.pb(0);
            else b.pb(mm/10);
            b.pb(mm%10);
            auto c=Rev(b);
            int nh,nm;
            if(!c.empty())nh=c[3]*10+c[2],nm=c[1]*10+c[0];
            if(!c.empty()&&nh<h&&nm<m){
                printf("%i%i:%i%i\n",b[0],b[1],b[2],b[3]);
                break;
            }
            n++;
        }
    }
    return 0;
}