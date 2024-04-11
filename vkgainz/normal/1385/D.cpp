#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int solve(string curr, int x){
    if(curr.length()==1){
        if((curr[0]-'a')!=x){
            return 1;
        }
        return 0;
    }
    int dist1= 0;
    int dist2=0;
    for(int i=0;i<curr.length()/2;i++){
        if((curr[i]-'a')!=x){
            dist1++;
        }
        if((curr[i+curr.length()/2]-'a')!=x){
            dist2++;
        }
    }
    return min(dist1+solve(curr.substr(curr.length()/2,curr.length()),x+1),dist2+solve(curr.substr(0,curr.length()/2),x+1));
}
int main(){
    cin >> t;
    while(t--){
        string s;
        cin >> n >> s;
        cout << solve(s,0) << endl;
    }
}