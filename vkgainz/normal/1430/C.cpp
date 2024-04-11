#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        cout << 2 << endl;
        while(nums.size()>1) {
            cout << nums[nums.size()-1] << " " << nums[nums.size()-2] << endl;
            int next=  (nums[nums.size()-1]+nums[nums.size()-2]+1)/2;
            nums.pop_back();
            nums.pop_back();
            nums.push_back(next);
        }
    }
	
}