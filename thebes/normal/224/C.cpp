#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
stack<pair<char,int>> st;
int mat[MN], i, j, vis[MN], dp[MN], psa[MN], ans;
string s; int ind;

void fnd(int n){
	if(vis[n]||mat[n]<n) return;
	vis[n] = 1; fnd(mat[n]+1);
	dp[n]=mat[n]-n+1+dp[mat[n]+1];
}

int sum(int x,int y){
	return (x)?psa[y]-psa[x-1]:psa[y];
}

int main(){
	cin >> s;
	for(i=0;i<s.size();i++){
		char ch = s[i];
		if(ch==')'){
			if(!st.size()||st.top().first!='('){
				// reeeeeeeeeeeeeeeeeeeeeeeee
				while(st.size()){
					mat[st.top().second]=-1;
					st.pop();
				}
				mat[i] = -1;
			}
			else{
				mat[st.top().second]=i;
				st.pop();
			}
		}
		else if(ch==']'){
			if(!st.size()||st.top().first!='['){
				while(st.size()){
					mat[st.top().second]=-1;
					st.pop();
				}
				mat[i]=-1;
			}
			else{
				mat[st.top().second]=i;
				st.pop();
			}
		}
		else st.push({ch,i});
		psa[i]=psa[i-1]+(ch=='[');
	}
	while(st.size()){
		mat[st.top().second]=-1;
		st.pop();
	}
	for(i=0;i<s.size();i++){
		fnd(i); if(!dp[i]) continue;
		if(sum(i,i+dp[i]-1)>ans){
			ans = sum(i,i+dp[i]-1);
			ind = i;
		}
	}
	if(ans)	printf("%d\n%s\n",ans,s.substr(ind,dp[ind]).c_str());
	else printf("0\n");
	getchar(); getchar();
	return 0;
}