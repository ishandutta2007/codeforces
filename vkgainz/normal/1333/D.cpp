#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<int> &x){
    printf("%d ",x.size());
    for(int i : x) printf("%d ",i);
    printf("\n");
}
int main(){
    int n,k;
    cin >> n >> k;
    string s; cin >> s;
    vector<int> buckets[5000];
    int num = 0;
    int tot = 0;
    bool cont = true;
    while(cont){
        cont = false;
        for(int j=0;j<s.length()-1;j++){
            if(s[j]=='R' && s[j+1]=='L'){
                cont = true;
                buckets[num].push_back(j+1);
                s[j] = 'L';
                s[j+1] = 'R';
                ++j;
                ++tot;
            }
        }
        if(cont) ++num;
    }
    
    if(k<num || k>tot){
        cout << -1 << endl;
    }
    else{
        for(int i=0;i<num;i++){
            vector<int> temp;
            for(int j : buckets[i]){
                temp.push_back(j);
                if(tot==k){
                    print(temp);
                    temp.clear();
                    --k;
                }
                --tot;
            }
            if(!temp.empty()){
                print(temp);
                --k;
            }
        }
    }
}