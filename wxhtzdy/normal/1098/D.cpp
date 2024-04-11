#include <bits/stdc++.h>
using namespace std;
const int L=32;
int q,sz;
multiset<int> vals[L];
long long sum[L];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>q;
    while(q--){
        char op;cin>>op;
        int x;cin>>x;
        if(op=='+'){
			sz++;
			for(int i=0;i<=30;i++){
				if((1<<i)<=x&&x<(1<<(i+1))){
					vals[i].insert(x);
					sum[i]+=x;
					break;
				}
			}
        }else{
			sz--;
			for(int i=0;i<=30;i++){
                if((1<<i)<=x&&x<(1<<(i+1))){
					vals[i].erase(vals[i].find(x));
                    sum[i]-=x;
                    break;
				}
			}
        }
        int ans=sz;
        long long s=0;
        for(int i=0;i<=30;i++){
            if(!vals[i].empty()&&*vals[i].begin()>s*2)ans--;
            s+=sum[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}