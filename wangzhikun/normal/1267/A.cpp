#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,a,b,t;

/*
    EVENT TYPE:
        0 : Appear!
        1 : Disappear!
        2 : Operate!
*/

struct event{
    ll t,typ,info;
    bool operator > (const event &rhs) const{
        if(t!=rhs.t)return t>rhs.t;
        return typ>rhs.typ;
    }
};

priority_queue< event,vector<event>,greater<event> > Q;

multiset<ll> Cu;
multiset<ll> presee;

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>t;
        if(b-a<t)continue;
        presee.insert(a+t);
        Q.push((event){a,0,t});
        Q.push((event){b-t+1,1,t});
    }
    Q.push((event){0,2,0});
    ll ans = 0;
    while(!Q.empty()){
        event cc = Q.top();Q.pop();
        /*if(cc.typ == 2){
            cout<<cc.t<<' '<<ans<<endl;
        }*/
        if(cc.typ == 0){
            presee.erase(presee.find(cc.t+cc.info));
            Cu.insert(cc.info);
        }
        if(cc.typ == 1){
            Cu.erase(Cu.find(cc.info));
        }
        if(cc.typ == 2){
            if(!Cu.size()){
                if(!presee.size()){
                    continue;
                }else{
                    ll nx = *presee.begin();
                    ans = ans+1;
                    Q.push((event){nx,2,0});
                }
            }else{
                ll mi = *Cu.begin()+cc.t;
                ll req = mi-cc.t;
                if(presee.size() && *presee.begin()<mi){
                    ans = ans+1;
                    Q.push((event){*presee.begin(),2,0});
                    continue;
                }else{
                    event nxte = Q.top();
                    //cout<<nxte.t<<' '<<cc.t<<' '<<req<<endl;
                    ll cyct = max(1ll,(nxte.t-cc.t)/req);
                    ans+=cyct;
                    Q.push((event){cc.t+cyct*req,2,0});
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}