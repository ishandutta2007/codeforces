#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<pair<int,int>,int> &x, const pair<pair<int,int>,int> &y){
    return x.first.first>y.first.first;
}
bool bmp(const pair<pair<int,int>,int> &x, const pair<pair<int,int>,int> &y){
    return x.first.first<y.first.first;
}
int main(){
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> less;
    vector<pair<pair<int,int>,int>> more;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(a<b) less.push_back(make_pair(make_pair(b,a),i));
        else more.push_back(make_pair(make_pair(b,a),i));
    }
    sort(less.begin(),less.end(),cmp);
    sort(more.begin(),more.end(),bmp);
    if(less.size()<more.size()){
        cout << more.size() << endl;
        for(auto &it : more)
            cout << it.second+1 << endl;
    }
    else{
        cout << less.size() << endl;
        for(auto &it : less)
            cout << it.second+1 << endl;
    }

}