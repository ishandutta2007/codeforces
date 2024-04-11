#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> ans;
int n;
bool work;
void shift(int i, vector<int> &nums) {
    tuple<int,int,int> temp = {nums[i],nums[i+1],nums[i+2]};
    nums[i] = get<2>(temp);
    nums[i+1] = get<0>(temp);
    nums[i+2] = get<1>(temp);
    ans.push_back(i);
}
void move(int idx, int pos, vector<int> &nums) {
    if(idx==pos) return;
    else if(idx==pos+1) {
        shift(pos,nums);
        shift(pos,nums);
        return;
    }
    else {
        shift(idx-2,nums);
        move(idx-2,pos,nums);
    }
}
void finish(vector<int> &nums) {
    if(nums[n-2]<=nums[n-1]) {
        work = true;
        return;
    }
    if(nums[n-3]==nums[n-1]) {
        shift(n-3,nums);
        work = true;
        return;
    }
    int eq = -1;
    for(int i=0;i<n-1;i++) if(nums[i]==nums[i+1]) eq = i+1;
    if(eq==-1) {
        work = false;
        return;
    }
    work = true;
    shift(n-3,nums);
    if(eq==n-2) {
        return;
    }
    else {
        for(int i=n-4;i>=eq;i--) {
            shift(i,nums);
        }
        shift(eq-1,nums);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        vector<int> nums(n);
        work = false;
        ans.clear();
        for(int i=0;i<n;i++) cin >> nums[i];
        vector<int> idx(n);
        //get positions
        for(int i=0;i<n-2;i++) {
            int mn = 1000000, idx = -1;
            for(int j=i;j<n;j++) {
                if(nums[j]<mn) {
                    mn = nums[j];
                    idx = j;
                }
            }
            move(idx,i,nums);
        }
        finish(nums);
        if(!work) cout << -1 << endl;
        else {
            cout << ans.size() << endl;
            for(auto &it : ans) cout << it+1 << " ";
            cout << endl;
        }
    }
}