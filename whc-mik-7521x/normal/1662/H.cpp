#include<bits/stdc++.h>
using namespace std;
int t,w,l;
vector<int>ans;
bool check(int x){
    int i=0;
	while(i<16){
		int s1=w-2,s2=w-2,s3=l-2,s4=l-2;
		if(i&1)s1++;
		else s3++;
		if(i&2)s1++;
		else s4++;
		if(i&4)s2++;
		else s3++;
		if(i&8)s2++;
		else s4++;
		if(s1%x==0&&s2%x==0&&s3%x==0&&s4%x==0)return 1;
        i++;
    }
	return 0;
}
void calc(int x){
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			if(check(i))ans.push_back(i);
			if(check(x/i))ans.push_back(x/i);
		}
    }
}
void solve(){
	cin>>w>>l;
    ans.clear();
    for(int i=w;i>=w-2;i--)calc(i);
    for(int i=l;i>=l-2;i--)calc(i);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	cout<<(int)ans.size()<<' ';
	for(auto x:ans)cout<<x<<' ';
	puts("");
}
int main(){
    cin>>t;
	while(t--) solve();
	return 0;
}