#include <bits/stdc++.h>
using namespace std;
#define ll long long
int getNumLess(vector<int>&nums, int a) {
    int ans = 0;
    for(int i=1;i<1<<nums.size();i++) {
        int cnt = 0;
        int prod = 1;
        for(int j=0;j<nums.size();j++) {
            if((1<<j)&i) {
                ++cnt;
                prod*=nums[j];
            }
        }
        if(cnt%2) {
            ans+=a/prod;
        }
        else {
            ans-=a/prod;
        }
    }
    return a-ans;
}
int binarySearch(int lo,int hi,vector<int>&nums, int t){
    int mid = (lo+hi)/2;
    if(getNumLess(nums,mid)>=t) {
        if(getNumLess(nums,mid-1)<t) return mid;
        return binarySearch(lo,mid-1,nums,t);
    }
    return binarySearch(mid+1,hi,nums,t);
}
int main() {
    int t; cin >> t;
    while(t--) {
        int x,p,k;
        cin >> x >> p >> k;
        vector<int> primes;
        int temp = p;
        for(int i=2;i*i<=temp;i++) {
            if(temp%i==0) {
                while(temp%i==0) {
                    temp/=i;
                }
                primes.push_back(i);
            }
        }
        if(temp>1) primes.push_back(temp);
        k+=getNumLess(primes,x);
        cout << binarySearch(1,1000000000,primes,k) << endl;
    }
}