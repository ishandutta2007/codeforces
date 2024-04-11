#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,s,a[N];
vector<pair<int,int>>ans;
int main(){
    scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        s=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),s+=a[i];
        if(s&1){puts("-1");continue;}
        int i=1;
        while(i<=n){
            if(s<0&&a[i+1]==-1){
                ans.push_back({i,i+1});
                i+=2;
                s+=2;
            }
            else if(s>0&&a[i+1]==1){
                ans.push_back({i,i+1});
                i+=2;
                s-=2;
            }
            else ans.push_back({i,i}),i++;
        }
        printf("%d\n",(int)ans.size());
        for(auto it:ans)printf("%d %d\n",it.first,it.second);
        ans.clear();
    }
	return 0;
}