#include <bits/stdc++.h>
using namespace std;

int m,n,k,t;
map<pair<int, int>, int> traps;
bool works(int br){
    set<pair<int,int>> curr;
    auto it = traps.begin();
    while(it!=traps.end()){
        if((*it).second>br){
            curr.insert({(*it).first.first,(*it).first.second});
        }
        it++;
    }
    int totTime = n+1;
    if(curr.size()==0){
        return totTime<=t;
    }
    auto x = curr.begin();
    int minL = (*x).first;
    int maxR = (*x).second;

    
    while(x!=curr.end()){

        if((*x).first>maxR){
            totTime+=2*(maxR-minL+1);
            minL = (*x).first;
            maxR = (*x).second;
            
        }
        else{
            maxR = max(maxR,(*x).second);
        }
        x++;
    }
    totTime+=2*(maxR-minL+1);
    return totTime<=t;
}
int binarySearch(int lo,int hi,int a[]){
    int mid = (lo+hi)/2;
    if(works(a[lo])){
        return lo;
    }
    if(works(a[mid])){
        if(mid-1>=0 && !works(a[mid-1])){
            return mid;
        }
        return binarySearch(lo,mid-1,a);
    }
    else{
        return binarySearch(mid+1,hi,a);
    }
}

void solve(int a[]){
    sort(a,a+m);
    int ans = binarySearch(0,m-1,a);
    cout << m-ans << endl;
}
int main(){
    scanf("%d%d%d%d",&m,&n,&k,&t);
    int a[m];
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<k;i++){
        int l, r, d;
        scanf("%d%d%d",&l,&r,&d);
        pair<int,int> x = {l,r};
        if(traps.find(x)==traps.end()){
            traps[x] = d;
        }
        else{
            traps[x] = max(traps[x],d);
        }
    }
    solve(a);
    
}