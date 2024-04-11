#include <bits/stdc++.h>
using namespace std;
#define ll long long
int q;
vector<pair<int,int>> v;
//x is a power of 2
void make_pair_naive(int x,int add){
    if(x==1) return;
    make_pair_naive(x/2,add);
    make_pair_naive(x/2,add+x/2);
    for(int i=0;i<x/2;i++){
        v.push_back({i+add,i+x/2+add});
    }
}
void make_pair(int x,int add){
    if(x==1) return;
    int next = add;
    vector<int> nums;
    vector<int> buckets[20];
    for(int j=19;j>=0;j--){
        if(1<<j <x){
            make_pair_naive(1<<j,next);
            for(int i=0;i<1<<j;i++) buckets[j].push_back(i+next);
            next+=1<<j;
            x-=1<<j;
        }
        else if(1<<j==x){
            make_pair_naive(1<<j,next);
            for(int i=0;i<1<<j;i++) buckets[j].push_back(i+next);
            next+=1<<j;
            x-=1<<j;
        }
    }
    int lastBucket = 20;
    for(int j=19;j>=0;j--){
        if(!buckets[j].empty()){
            lastBucket = j;
            break;
        }
    }
    int firstBucket = 0;
    for(int i=0;i<20;i++){
        if(!buckets[i].empty()){
            firstBucket=  i;
            break;
        }
    }
    for(int i=firstBucket+1;i<lastBucket;i++){
        if(buckets[i].empty()) continue;
        if(buckets[i].size()==buckets[firstBucket].size()){
            int t = buckets[firstBucket].size();
            for(int j=0;j<t;j++){
                v.push_back({buckets[i][buckets[i].size()-1],buckets[firstBucket][j]});
                buckets[firstBucket].push_back(buckets[i][buckets[i].size()-1]);
                buckets[i].pop_back();
            }

        }
        else if(buckets[i].size()>buckets[firstBucket].size()){
            int t = buckets[firstBucket].size();
        //double its size
            for(int j=0;j<t;j++){
                v.push_back({buckets[lastBucket][buckets[lastBucket].size()-1],buckets[firstBucket][j]});
                buckets[firstBucket].push_back(buckets[lastBucket][buckets[lastBucket].size()-1]);
                buckets[lastBucket].pop_back();
            }
            --i;
        }
    }
}
int main(){
    int n; cin >> n;
    make_pair(n,1);
    cout << v.size() << endl;
    for(auto &it : v){
        cout << it.first << " " << it.second << endl;
    }
}