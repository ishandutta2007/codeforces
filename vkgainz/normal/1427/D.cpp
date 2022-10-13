#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
int c[52];
int n;
vector<int> ans;
int numq;
void query(vector<int> &nums) {
    if(nums.size()==1 && nums[0]==n) return;
    ans.push_back(nums.size());
    for(auto &it : nums) ans.push_back(it);
    int start = 0;
    int end = n;
    int r[n];
    for(auto &it : nums) {
        vector<int> temp;
        for(int x=start;x<start+it;x++){
            temp.push_back(c[x]);
        }
        start+=it;
        end-=it;
        for(auto &x : temp) {
            r[end++] = x;
        }
        end-=it;
    }
    for(int i=0;i<n;i++) c[i] = r[i];
}
int main() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=2;i<=n;i++){
        //construct 1...i or i...1
        int targetPos = 0;
        int start = 0;
        int end = 0;
        bool dec = 0;
        for(int j=0;j<n;j++){
            if(c[j]==i) targetPos = j;
            if(c[j]==1) start = j;
            if(c[j]==i-1) end = j;
        }
        dec= start>end;
        vector<int> curr;
        if(dec) {
            if(targetPos<end) {
                if(targetPos>0){
                    curr.push_back(targetPos);
                }
                curr.push_back(end-targetPos);
                for(int i=end;i<=start;i++){
                    curr.push_back(1);
                }
                if(n-start-1>0) curr.push_back(n-start-1);
            }
            else if(targetPos>start) {
                if(end>0) {
                    curr.push_back(end);
                }
                curr.push_back(start-end+1);
                curr.push_back(targetPos-start);
                if(n-targetPos-1>0) curr.push_back(n-targetPos-1);
            }
        }
        else {
            if(targetPos<start) {
                if(targetPos>0) {
                    curr.push_back(targetPos);
                }
                curr.push_back(start-targetPos);
                curr.push_back(end-start+1);
                if(n-end-1>0) curr.push_back(n-end-1);
            }
            else if(targetPos>end) {
                if(start>0) {
                    curr.push_back(start);
                }
                for(int i=start;i<=end;i++){
                    curr.push_back(1);
                }
                curr.push_back(targetPos-end);
                if(n-targetPos-1>0) curr.push_back(n-targetPos-1);
            }
        }
        query(curr);
        ++numq;
        
    }
    if(c[0]==n && n>1){
        ++numq;
        ans.push_back(n);
        for(int i=1;i<=n;i++){
            ans.push_back(1);
        }
    }
    cout << numq << endl;
    for(auto &it : ans) cout << it << " ";
    
}