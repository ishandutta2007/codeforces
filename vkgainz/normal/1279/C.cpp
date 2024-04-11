#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int a[n];
        int b[m];
        map<int,int> x;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];
        for(int i=0;i<m;i++){
            x[b[i]] = i;
        }
        for(int i=0;i<n;i++){
            if(x.find(a[i])!=x.end()){
                a[i] = x[a[i]];
            }
            else{
                a[i] = 1000000000;
            }
        }
        int search = 0;
        set<int> s;
        for(int i=0;i<m;i++){
            s.insert(i);
        }
        vector<int> nums;
        for(int i=0;i<n;i++){
            auto front = s.begin();
            if(a[i]==*front){
                nums.push_back(i);
                s.erase(front);
            }
            else{
                if(s.find(a[i])!=s.end()){
                    front = s.find(a[i]);
                    s.erase(front);
                }
            }
        }
        long long ret =0;
        for(int i=0;i<nums.size();i++){
            ret+=2*(nums[i]-a[nums[i]])+1;
        }
        ret+=m-nums.size();
        cout << ret << endl;
    }
}