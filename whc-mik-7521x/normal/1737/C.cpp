#include<bits/stdc++.h>
using namespace std;
int T,X,n,t[3],Y;
vector<pair<int,int>>v(3);
void init(){
    for(int i:{0,1,2}){
        for(int o=i+1;o<3;o++){
            if(v[i].first==v[o].first)t[i]++,t[o]++;
            if(v[i].second==v[o].second)t[i]++,t[o]++;
        }
    }
    if(t[1]==2)swap(v[0],v[1]);
    if(t[2]==2)swap(v[0],v[2]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
	while(T--){
        cin>>n;
        t[1]=t[2]=t[0]=0;
        for(auto &[x,y]:v)cin>>x>>y;
        cin>>X>>Y;
        init();
        if(v[0]==make_pair(1,1)||v[0]==make_pair(1,n)||v[0]==make_pair(n,1)||v[0]==make_pair(n,n)) {
            if((X!=v[0].first)&&(Y!=v[0].second)) puts("NO");
            else puts("YES");
            continue;
        }
        puts(((X-v[0].first)&1) && ((Y-v[0].second)&1)?"NO":"YES");
    }
	return 0;
}