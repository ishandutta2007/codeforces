#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>op;
vector<int>cl;
void solve(int now,int mul){
	if(now<=2){for(int i=1;i<=now;i++)cl.push_back(i*mul);return;}
	int msk=1;
	while(msk*2<=now)msk*=2;
	if(msk==now){
		cl.push_back(now*mul);
		now--,msk/=2;
	}
	cl.push_back(msk*mul);
	for(int i=msk+1;i<=now;i++){
		cl.push_back(2*msk*mul);
		op.push_back({i*mul,(2*msk-i)*mul});
	}
	solve(2*msk-now-1,mul);
	solve(now-msk,mul*2);
}
int n;
int main(){
	int t;
    scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        if(n==2){
            puts("-1");
            continue;
        }
        solve(n,1);
        sort(cl.begin(),cl.end());
        int ans=1;
        while(ans<n)ans*=2;
        for(int i=0;i>=0;i++){
            if(cl[i]==cl[i+1]){
                op.push_back({cl[i],cl[i]});
                cl[i+1]*=2;
                cl.erase(cl.begin()+i);
                break;
            }
        }
        for(auto x:cl){
            while(x!=ans){
                op.push_back({0,x});
                op.push_back({x,x});
                x*=2;
            }
        }
        op.push_back({0,ans});
        printf("%d\n",(int)op.size());
        for(int i=0;i<(int)op.size();i++){
            printf("%d %d\n",op[i].first,op[i].second);
        }
        op.clear();
        cl.clear();
    }
}