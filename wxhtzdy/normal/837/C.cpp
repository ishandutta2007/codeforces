#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
vector<pii> v;
int main(){
    int n,a,b;scanf("%i%i%i",&n,&a,&b);
    for(int i=1;i<=n;i++){
        int x,y;scanf("%i%i",&x,&y);
        v.pb({x,y});
    }
    int ans=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
			if(i==j)continue;
            if(v[i].first+v[j].first<=a&&max(v[i].second,v[j].second)<=b){
                ans=max(ans,v[i].first*v[i].second+v[j].first*v[j].second);
            }
            if(v[i].second+v[j].second<=b&&max(v[i].first,v[j].first)<=a){
                ans=max(ans,v[i].first*v[i].second+v[j].first*v[j].second);
            }
            swap(v[i].first,v[i].second);
			if(v[i].first+v[j].first<=a&&max(v[i].second,v[j].second)<=b){
                ans=max(ans,v[i].first*v[i].second+v[j].first*v[j].second);
            }
            if(v[i].second+v[j].second<=b&&max(v[i].first,v[j].first)<=a){
                ans=max(ans,v[i].first*v[i].second+v[j].first*v[j].second);
            }
            swap(v[i].first,v[i].second);
            swap(v[j].first,v[j].second);
			if(v[i].first+v[j].first<=a&&max(v[i].second,v[j].second)<=b){
                ans=max(ans,v[i].first*v[i].second+v[j].first*v[j].second);
            }
            if(v[i].second+v[j].second<=b&&max(v[i].first,v[j].first)<=a){
                ans=max(ans,v[i].first*v[i].second+v[j].first*v[j].second);
            }
            swap(v[i].first,v[i].second);
			if(v[i].first+v[j].first<=a&&max(v[i].second,v[j].second)<=b){
                ans=max(ans,v[i].first*v[i].second+v[j].first*v[j].second);
            }
            if(v[i].second+v[j].second<=b&&max(v[i].first,v[j].first)<=a){
                ans=max(ans,v[i].first*v[i].second+v[j].first*v[j].second);
            }
            swap(v[i].first,v[i].second);
            swap(v[j].first,v[j].second);
		}
    }
    printf("%i",ans);
	return 0;
}