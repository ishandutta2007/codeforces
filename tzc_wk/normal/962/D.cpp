#include <bits/stdc++.h>
using namespace std;
#define y1 ABC1
#define y2 ABC2
#define int long long
int n;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
struct cmp{
    bool operator()(pair<int,int> x,pair<int,int> y){
        return x.second>y.second;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> s;
signed main(){
	cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        q.push({x,i});
    }
    while(q.size()>1){
        int x1=q.top().first,y1=q.top().second;q.pop();
        int x2=q.top().first,y2=q.top().second;
        if(x1==x2)
			q.pop(),q.push({x1*2,y2});
        else
			s.push(make_pair(x1,y1));
    }
    s.push(q.top());
	cout<<s.size()<<endl;
    while(s.size()){
		cout<<s.top().first<<" ";
        s.pop();
	}
    return 0;
}